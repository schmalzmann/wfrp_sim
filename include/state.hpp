#pragma once

#include <string>

#include "utility.hpp"

/*
* This class provides state objects. States are all kinds of modifiers that apply to an entity that are
* considered static in the sense that they don't evolve. The talent "warrior born" provides a static
* +5 bonus to weapon skill. Thus the talent will provide a state of the same name to an entity.
* The modifier is then applied once and not monitored unless it's explicitly called for.
*/

class Entity;
class State {
    public:
        State(std::function<void(Entity*)>* method);
        ~State();

        void Apply(Entity*);
    private:
        //A state should not have internal variables besides the loaded method. It gets applied via Apply() and that's it.
        std::function<void(Entity*)>* m_loaded_state;
};