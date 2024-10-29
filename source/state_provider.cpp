#include "state_provider.hpp"
#include "entity.hpp"

StateProvider::StateProvider(){
    Initialize();
}

StateProvider::~StateProvider(){
    
}

void StateProvider::Initialize(){

    /*
    * I'd say being dead is a pretty static state :D
    */
    m_state_map[states::dead] = [&](Entity* entity){
        /*being dead is a special state in the sense that this is pretty much final and
        * the afflicted entity can't really do anything anymore. Maybe develop other code first
        * before implementing this one...
        */
    };
}