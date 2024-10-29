#pragma once

#include <iostream>
#include <string>

#include "feature.hpp"

//attribute class, super basic just to have in/out trigger capability
//additionally to feature functionality, attributes are basically just numbers and behave like
//integers in many ways (similar to the die class minus some methods like Flip() or Roll())
//attributes can be Set(), the current value can be queried (Get()) and modified (Mod())
class Attribute : public Feature{
    public:
        Attribute(const std::string& name, int level);
        Attribute(const Attribute& att);
        ~Attribute();

        int GetModifiedValue(){return m_value + m_mod;};
        int GetMod(){return m_mod;};
        void SetMod(int mod){m_mod = mod;};
        void AddMod(int mod){m_mod += mod;};

        //iostream
        friend std::ostream& operator<< (std::ostream& stream, const Attribute& die);
    
    private:
        int m_mod;
};