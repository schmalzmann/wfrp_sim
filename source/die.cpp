#include "die.hpp"

Die::Die(int sides)
    :m_rng(m_randDev())
    ,m_dist(std::uniform_int_distribution<>(1,sides))
{
    m_sides = sides;
}

Die::Die(const Die& d){
    Die(d.m_sides);
}

Die::~Die(){

}

void Die::Flip(){
    //extract digits
    int single = m_value%10;
    int tens = m_value/10;
    //flip digits
    m_value = single*10+tens;
}

void Die::Roll(){
    m_value = m_dist(m_rng);
}

void Die::Set(int value){
    if(value >= 1 && value <= m_sides) m_value = value;
    else std::cout << "Cannot set invalid die value." << std::endl;
}

Die operator+(const Die& die1, const int& value){
    Die newDie(die1.m_sides);
    newDie.m_value = die1.m_value + value;
    return newDie;
}

Die operator+(const int& value, const Die& die1){
    return operator+(die1,value);
}

Die operator-(const Die& die1, const int& value){
    Die newDie(die1.m_sides);
    newDie.m_value = die1.m_value - value;
    return newDie;
}

Die operator-(const int& value, const Die& die1){
    return operator-(die1, value);
}

Die operator+(const Die& die1, const Die& die2){
    Die newDie(die1.m_sides);
    newDie.m_value = die1.m_value + die2.m_value;
    return newDie;
};

Die operator-(const Die& die1, const Die& die2){
    Die newDie(die1.m_sides);
    newDie.m_value = die1.m_value - die2.m_value;
    return newDie;
};

auto Die::operator=(int value) -> decltype(value) {
    m_value = value;
    return m_value;
}

auto Die::operator=(const Die& rhs) -> decltype(rhs) {
    if (this != &rhs) { // Self-assignment check
        m_sides = rhs.m_sides;
        m_dist = std::uniform_int_distribution<>(1,m_sides);
        m_value = rhs.m_value;
    }
    return *this;
}

std::ostream& operator<< (std::ostream& stream, const Die& die){
    stream << die.m_value;
    return stream;
}