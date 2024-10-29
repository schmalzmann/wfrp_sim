#pragma once

#include <random>
#include <iostream>
#include <type_traits>

class Die{
    private:
        int m_sides;
        int m_value;

        std::random_device m_randDev;
        std::mt19937 m_rng;
        std::uniform_int_distribution<int> m_dist;

    public:
        Die(int sides = 100);
        Die(const Die& d);
        ~Die();

        void Flip();
        void Roll();
        void Set(int value);

        int GetValue(){return m_value;};
        int GetSides(){return m_sides;};

        //in many ways, the die should just behave like a positive integer in [1,sides]
        //so it should be possible to do simple math on dies like addition or multiplication
        //furthermore, if a die is passed to any function that expects an integer, this should work with the
        //die value being passed over as an int
        friend Die operator+(const Die& die1, const int& value);
        friend Die operator-(const Die& die1, const int& value);
        friend Die operator+(const int& value, const Die& die1);
        friend Die operator-(const int& value, const Die& die1);
        friend Die operator+(const Die& die1, const Die& die2);
        friend Die operator-(const Die& die1, const Die& die2);

        // implicit conversion to int
        explicit operator int() const {return m_value;}

        // Assignment operator for Die
        auto operator=(const Die& rhs) -> decltype(rhs);

        // Assignment operator for int
        auto operator=(int value) -> decltype(value);

        // Move constructor
        Die(Die&& other);

        // Move assignment operator
        Die& operator=(Die&&) noexcept = default;

        // iostream
        friend std::ostream& operator<< (std::ostream& stream, const Die& die);
        
};