#pragma once

/*
* This class is a pure manager class to invoke single instances of e.g. the ActionProvider, CriticalProvider,
* and all other classes which are needed by several other classes and should be only instantiated once.
*/

#include "action_provider.hpp"
#include "critical_provider.hpp"
#include "state_provider.hpp"
#include "condition_provider.hpp"

class Overhead {
    public:
        Overhead();
        ~Overhead();

        const ActionProvider* const GetActionProvider() {return m_action_provider;};
        const CriticalProvider* const GetCriticalProvider() {return m_critical_provider;};
        const StateProvider* const GetStateProvider() {return m_state_provider;};
        const ConditionProvider* const GetConditionProvider() {return m_condition_provider;};

    private:
        void Initialize();
        ActionProvider* m_action_provider;
        CriticalProvider* m_critical_provider;
        StateProvider* m_state_provider;
        ConditionProvider* m_condition_provider;

};