#pragma once
//new try
//this class is meant to be a single node in a gradually evolving decision tree as the simulation progresses through
//an action sequence. for example: one entity makes a melee_basic test to attack another. then check if this
//was a critical success/fail and handle that, then return to the original roll (if nobody died) and
//proceed with the defensive test of the attacked. then check again if it's a critical and then
//oppose the rolls and do damage if needed. all this will require a decision tree that gradually unfolds
//as the sequence progresses.
//the action

#include <iostream>

#include "die.hpp"
#include "utility.hpp"
#include "overhead.hpp"

class ActionNode {
    public:

        ActionNode(std::function<void(actions::action_node_data&)>* method, ActionNode* previous);
        ~ActionNode();

        //this virtual wrapper will be used to load a custom action method into a new instance of
        //an ActionNode
        void Execute();

        //move up in the tree by n levels
        ActionNode* GetPrevious(unsigned int n);

        //this container is a struct defined in the framework and should be a static object
        //the idea is that any method loaded into "Execute" gets this container to work with
        //so the action methods all have the same signature void Action(struct) which will make
        //storing them in a map much easier and also means I don't have to mess around with
        //variadic template functions
        actions::action_node_data data;

    private:
        ActionNode* m_previous;
        std::function<void(actions::action_node_data&)>* m_loaded_action;
};