#include "overhead.hpp"

Overhead::Overhead(){
    Initialize();
}

Overhead::~Overhead(){
    delete m_action_provider;
    delete m_critical_provider;
    delete m_state_provider;
    delete m_condition_provider;
}

void Overhead::Initialize(){
    m_action_provider = new ActionProvider();
    m_critical_provider = new CriticalProvider();
    m_state_provider = new StateProvider();
    m_condition_provider = new ConditionProvider();
}