#include "entity.hpp"

Entity::Entity(const toml::table& info)
    :m_info(info)
{
    ParseInfo();
}

Entity::Entity(const Entity& entity)
    :m_info(entity.m_info)
{

}

Entity::~Entity(){}

void Entity::ParseInfo(){
    //most basic info is name and type. any entity must contain these
    if(m_info.contains("name")){
        m_name = m_info["name"].as_string()->get();
    } else {
        std::cerr << "Entity has no name!" << std::endl;
        throw std::runtime_error("entity name not found");
    }

    if(m_info.contains("type")){
        m_type = m_info["type"].as_string()->get();
    } else {
        std::cerr << "Entity '" << m_name << "' has no type!" << std::endl;
        throw std::runtime_error("entity type not found");
    }

    //attributes must be present for any entity (even a wall has toughness)
    if(m_info.contains("attributes")){
        auto attributes = m_info["attributes"].as_array();
        for(auto&& elem: *attributes){
            std::string name = (*elem.as_array()).at(0).as_string()->get();
            if(m_attributes.find(name) == m_attributes.end()){
                int value = (int)(*elem.as_array()).at(1).as_integer()->get();
                auto newAttr = std::make_shared<Attribute>(name,value);
                std::cout << "Add attribute " << name << std::endl;
                m_attributes.emplace(name,std::move(newAttr));
            } else {
                std::cout << "Double definition of attribute " << name << ", ignoring second instance." << std::endl;
            }                
        }
    } else {
        std::cerr << "Entity '" << m_name << "' has no attributes!" << std::endl;
        throw std::runtime_error("entity type not found");
    }

    //now just read in whatever comes up
    for(auto&& [k,v]: m_info){
        if(k == "attributes") continue;
        else if(k == "skills"){
            for(auto&& elem: *v.as_array()){
                std::string name = (*elem.as_array()).at(0).as_string()->get();
                std::string category = (*elem.as_array()).at(1).as_string()->get();
                if(m_skills.find(name) == m_skills.end()){
                    int value = (int)(*elem.as_array()).at(2).as_integer()->get();
                    std::string base_name = utility::baseAttrName_from_skillName(name);
                    auto base = m_attributes[base_name];
                    if(base == nullptr){
                        std::cout << "Could not find base attribute for skill " << name << std::endl;
                        continue;
                    }
                    auto newSkill = std::make_shared<Skill>(name,category,base,value);
                    std::string skill_full_name = name;
                    if(category.length() > 0) skill_full_name += "_"+category;
                    std::cout << "Add new skill: " << skill_full_name << std::endl;
                    m_skills.emplace(skill_full_name,std::move(newSkill));
                } else {
                    std::cout << "Double definition of skill " << name << ", ignoring second instance." << std::endl;
                }                
            }
        }/* else if (k == "talents"){
            for(auto&& elem: *v.as_array()){
                std::string name = (*elem.as_array()).at(0).as_string()->get();
                std::string category = (*elem.as_array()).at(1).as_string()->get();
                if(m_talents.find(name) == m_talents.end()){
                    int rank = (*elem.as_array()).at(2).as_integer()->get();
                    talents::talent newTalent {
                        name,
                        category,
                        rank,
                        talents::talentID_talentName.right.find(name)->second
                    };
                    std::string talent_full_name = name+"_"+category;
                    m_talents[talent_full_name] = std::move(newTalent);
                } else {
                    std::cout << "Double definition of talent " << name << ", ignoring second instance." << std::endl;
                }
            }
        } else if(k == "traits"){
            for(auto&& elem: *v.as_array()){
                std::string name = (*elem.as_array()).at(0).as_string()->get();
                std::string category = (*elem.as_array()).at(1).as_string()->get();
                if(m_traits.find(name) == m_traits.end()){
                    int rating = (*elem.as_array()).at(2).as_integer()->get();
                    traits::trait newTrait {
                        name,
                        category,
                        rating,
                        traits::traitID_traitName.right.find(name)->second
                    };
                    std::string trait_full_name = name+"_"+category;
                    m_traits[name] = std::move(newTrait);
                } else {
                    std::cout << "Double definition of trait " << name << ", ignoring second instance." << std::endl;
                }
            }
        } */ else {
            if(k != "name" && k != "type"){
                std::cout << "Unknown entry " << k << ", doing nothing..." << std::endl;
            }

            continue;

        }
    }
}

void Entity::ClearModifiers(){
    for(auto& attribute: m_attributes) attribute.second->SetMod(0);
    for(auto& skill: m_skills) skill.second->SetMod(0);
}

std::shared_ptr<Attribute> Entity::GetAttribute(std::string name){
    auto it = m_attributes.find(name);
    if(it != m_attributes.end()) return it->second;
    else return nullptr;
};

std::shared_ptr<Skill> Entity::GetSkill(std::string name){
    auto it = m_skills.find(name);
    if(it != m_skills.end()) return it->second;
    else return nullptr;
};

int Entity::GetMaxWounds(){
    
}

void Entity::ModifyWounds(int n){

}

void Entity::Heal(unsigned int n){

}

void Entity::Damage(unsigned int n){

}

/*
talents::talent* Entity::GetTalent(std::string name){
    auto it = m_talents.find(name);
    return &(it->second);
};

traits::trait* Entity::GetTrait(std::string name){
    auto it = m_traits.find(name);
    return &(it->second);
};
*/

void Entity::AddEngagement(Engagement* engagement){
    m_engagements.push_back(engagement);
}

void Entity::DelEngagement(Engagement* engagement){
    //look up if the engagement is in the engagement list. if it is, remove it
    auto it = std::find(m_engagements.begin(),m_engagements.end(),engagement);
    if(it != m_engagements.end()) m_engagements.erase(it);
}