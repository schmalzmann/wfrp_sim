#include "condition.hpp"

Condition::Condition(std::function<void(Entity*, conditions::condition_data&)>* method){
    m_loaded_condition = method;
}

Condition::~Condition(){

}

