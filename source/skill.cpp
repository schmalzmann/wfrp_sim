#include "skill.hpp"

///////////////////////////////
//////////// Skill ////////////
///////////////////////////////

Skill::Skill(std::string name, std::string category, std::shared_ptr<Attribute> base, int level)
    :Feature(name,category,level)
    ,m_base(base)
    ,m_mod(0)
{}

Skill::Skill(const Skill& skill)
    :Feature(skill.m_name,skill.m_category,skill.m_value)
    ,m_base(skill.m_base)
    ,m_mod(0)
{}

Skill::~Skill(){}

std::ostream& operator<< (std::ostream& stream, const Skill& skill){
    stream << skill.m_name << " (" << skill.m_category << ") " << skill.m_value;
    return stream;
}