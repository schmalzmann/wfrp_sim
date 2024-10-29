#pragma once

/*
* This class will provide states that can be applied to entities.
* The idea of a state is that it is static. So, for example, a permanent modifier to weapon skill, as is the
* case for the Warrior Born talent. Same goes for a mangled ear or a mutation. These things should basically
* not change (although some method for that will be provided) and be applied statically with no further
* monitoring needed afterwards.
* The will be a class for Talents, Traits, etc. and depending on their effect (i.e. if it is static) their
* effects will degenerate into a state.
*/

#include "utility.hpp"

class Entity;
class StateProvider {
    public:
        StateProvider();
        ~StateProvider();

        std::function<void(Entity*)> GetState(states::state_id);

    private:
        std::unordered_map<states::state_id,std::function<void(Entity*)>> m_state_map;
        void Initialize();
};