#pragma once

/*
* This class provides methods to apply critical hits to an entity.
* There must only be one instance of this class to hold all the methods to apply criticals and
* manage pointers to them.
* Criticals are a mix of states and conditions and are handled separately, simply to mirror the
* implementation of the tabletop rules.
*/

#include "utility.hpp"

class Entity;
class CriticalProvider{
    public:
        CriticalProvider();
        ~CriticalProvider();

        /*
        * Hand over a pointer to the appropriate critical effect based on the area and severity of the crit.
        * Both these parameters are determined by a D100 roll and thus given as an integer.
        */
        std::function<void(Entity*)>* GetCritical(int area, int severity);
        std::function<void(Entity*)>* GetCritical(criticals::critical_id id);

    private:
        std::unordered_map<criticals::critical_id,std::function<void(Entity*)>> m_critical_map;
        void Initialize();
};