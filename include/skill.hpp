#pragma once

#include <memory>

#include "feature.hpp"
#include "attribute.hpp"

//skills are similar to attributes with the one addition that they are based on a specific attribute
//e.g. the climb skill is based on the strength attribute. 10 advances in climb together with a strength of 35
//results in a climb skill of 45
//skills therefore internally access the value of their base attribute and add that value to their advances
//to derive a skill value


class Skill : public Feature{
    public:
        Skill(std::string name, std::string category, std::shared_ptr<Attribute> base, int advances);
        Skill(const Skill& skill);
        ~Skill();

        std::shared_ptr<Attribute> GetBase(){return m_base;};
        int GetSkillValue(){return m_value+m_base->GetValue();};
        int GetModifiedSkillValue(){return m_value+m_base->GetValue()+m_mod;};

        int GetMod(){return m_mod;};
        void SetMod(int mod){m_mod = mod;};
        void AddMod(int mod){m_mod += mod;};

        //iostream
        friend std::ostream& operator<< (std::ostream& stream, const Skill& skill);

    private:
        //skills are based on an attribute
        std::shared_ptr<Attribute> m_base;
        int m_mod;
};