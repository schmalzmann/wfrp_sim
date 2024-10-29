#include "action_node.hpp"

ActionNode::ActionNode(std::function<void(actions::action_node_data&)>* action, ActionNode* previous){
    m_previous = previous;
    m_loaded_action = action;
}

ActionNode::~ActionNode(){

}

void ActionNode::Execute(){
    //call loaded action
    (*m_loaded_action)(data);
}