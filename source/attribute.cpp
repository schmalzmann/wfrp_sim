#include "attribute.hpp"

///////////////////////////////////
//////////// Attribute ////////////
///////////////////////////////////

Attribute::Attribute(const std::string& name, int level)
    :Feature(name,"none",level)
    ,m_mod(0)
{
    
}

Attribute::Attribute(const Attribute& att)
    :Feature(att.m_name,"none",att.m_value)
    ,m_mod(0)
{}

Attribute::~Attribute(){}

std::ostream& operator<< (std::ostream& stream, const Attribute& att){
    stream << att.m_name << " " << att.m_value;
    return stream;
}