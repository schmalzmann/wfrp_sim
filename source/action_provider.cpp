#include "action_provider.hpp"
#include "action_node.hpp"
#include "entity.hpp"

ActionProvider::ActionProvider(){
    Initialize();
}

ActionProvider::~ActionProvider(){

}

std::function<void(actions::action_node_data&)>* ActionProvider::GetAction(actions::action_id id){
    return &m_action_map[id];
}

void ActionProvider::Initialize(){

    /*
    *  This is probably the most fundamental operation in the whole simulator.
    *  The skill or attribute in question is retrieved from an enttity and tested against a D100
    *  and the result stored.
    */
    m_action_map[actions::action_id::simple_test] = [&](actions::action_node_data& data){
        data.d = std::make_unique<Die>(100);
        data.d->Roll();
        int level = 0;
        if(utility::isAttribute(data.test_name)){
            //test against attribute
            level = data.entity->GetAttribute(data.test_name)->GetModifiedValue();
            
        } else {
            //test against skill
            if(data.entity->GetSkill(data.test_name)){
                //entity has skill, test it
                level = data.entity->GetSkill(data.test_name)->GetModifiedSkillValue();
            } else {
                //entity does not have skill, fall back to attribute
                //skill format is 'base_category', take only 'base' and get the associated attribute from that
                std::string base_skill = data.test_name.substr(0,data.test_name.find_first_of("_"));
                std::string base_attr = utility::baseAttrName_from_skillName(base_skill);
                level = data.entity->GetAttribute(base_attr)->GetModifiedValue();
            }
        }

        data.success_level = (level - data.d->GetValue())/10;
    };

    /*
    *  This is a basic check that will be required after any simple test that is opposed.
    *  This method "trusts" that the previous node in the chain is a simple test from
    *  which the necessary info to check for a critical can be retrieved.
    *  Later, when I write the ActionTree class, I will have to implement rules on how
    *  nodes are allowed to be chained together.
    */
    m_action_map[actions::action_id::critical] = [&](actions::action_node_data& data){
        int roll = data.previous_node->data.d->GetValue();
        if(
            //default crit
            roll%11 == 0
            //crit with weapon with impale quality
            || (
                std::find(data.tags.begin(),data.tags.end(),"attack") != data.tags.end()
                && std::find(data.tags.begin(),data.tags.end(),"impale") != data.tags.end()
                && roll%10 == 0
            )
        ){
            //roll for crit location and category
            Die crit_loc(100),crit_cat;
            crit_loc.Roll();
            crit_cat.Roll();

            //figure out if the crit was a success of fail and call the appropriate entity

            //apply the crit

            //move on in the chain
            
        }
    };
}