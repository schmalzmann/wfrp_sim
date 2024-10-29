#pragma once

/*
* This class handles conditions. These are modifiers that evolve continuously, for example things like
* the bleeding effect which damages an entity each round according to the number of stacks of bleeding.
* This needs to be re-applied every round.
* Furthermore, conditions like "broken bone minor" have a maximum age and must track the passage of
* time and remove themselves or evolve into a state once a certain deadline has passed.
*/

#include "utility.hpp"

class Entity;
class Condition {
    public:
        Condition(std::function<void(Entity*,conditions::condition_data&)>* method);
        ~Condition();

        void Evolve(Entity*);

        conditions::condition_data data;

        //Methods to manage condition
        void SetAgeLimit(int n);
        void ModifyAgeCurrent(int n);
        void ModifyStack(int n);

    
    private:
        std::function<void(Entity*,conditions::condition_data&)>* m_loaded_condition;
};