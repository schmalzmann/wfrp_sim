#include "condition_provider.hpp"
#include "entity.hpp"

ConditionProvider::ConditionProvider(){
    Initialize();
}

ConditionProvider::~ConditionProvider(){

}

std::function<void(Entity*, conditions::condition_data&)>* ConditionProvider::GetCondition(conditions::condition_id id){
    return &m_condition_map[id];
}

void ConditionProvider::Initialize(){

    /*
    * Ablaze is a condition because it "evolves" in the sense that it damages the afflicted entity
    * each round, can have multiple stacks that can change and might also have an age that is relevant.
    * So it needs to be managed on a round-by-round basis 
    */
    m_condition_map[conditions::condition_id::ablaze] = [&](Entity* entity, conditions::condition_data& data){
        
    };
}