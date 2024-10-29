#include "state.hpp"

State::State(std::function<void(Entity*)>* method){
    m_loaded_state = method;
}

State::~State(){

}

void State::Apply(Entity* entity){
    (*m_loaded_state)(entity);
}