#include <gtest/gtest.h>
#include "die.hpp"

TEST(DieTest, Constructor) {
    Die die(6);
    EXPECT_EQ(die.GetSides(), 6);
}

TEST(DieTest, Roll) {
    Die die(6);
    die.Roll();
    EXPECT_GE(die.GetValue(), 1);
    EXPECT_LE(die.GetValue(), 6);
}

TEST(DieTest, Set) {
    Die die(6);
    die.Set(3);
    EXPECT_EQ(die.GetValue(), 3);
    die.Set(7); // Invalid value
    EXPECT_EQ(die.GetValue(), 3);
}

TEST(DieTest, Flip) {
    Die die(100);
    die.Set(12); // Set to a two-digit number
    die.Flip();
    EXPECT_EQ(die.GetValue(), 21); // Flipped value
}

TEST(DieTest, Addition) {
    Die die1(6);
    Die die2(6);
    die1.Set(3);
    die2.Set(4);
    Die result = die1 + die2;
    EXPECT_EQ(result.GetValue(), 7);
}

TEST(DieTest, AdditionWithInt) {
    Die die(6);
    die.Set(3);
    Die result = die + 2;
    EXPECT_EQ(result.GetValue(), 5);
}

TEST(DieTest, Subtraction) {
    Die die1(6);
    Die die2(6);
    die1.Set(5);
    die2.Set(2);
    Die result = die1 - die2;
    EXPECT_EQ(result.GetValue(), 3);
}

TEST(DieTest, SubtractionWithInt) {
    Die die(6);
    die.Set(5);
    Die result = die - 2;
    EXPECT_EQ(result.GetValue(), 3);
}

TEST(DieTest, CopyConstructor) {
    Die die1(6);
    die1.Set(3);
    Die die2(die1); // Copy constructor
    EXPECT_EQ(die2.GetValue(), 3);
}

TEST(DieTest, AssignmentOperator) {
    Die die1(6);
    die1.Set(3);
    Die die2(6);
    die2 = die1; // Assignment operator
    EXPECT_EQ(die2.GetValue(), 3);
}

TEST(DieTest, Destructor) {
    Die die(6);
    die.Set(3);
    // Destructor is called automatically when die goes out of scope
    EXPECT_EQ(die.GetValue(), 3); // Check if value is still accessible
}

TEST(DieTest, InvalidSides) {
    Die die(-1); // Invalid sides
    EXPECT_EQ(die.GetSides(), 1); // Assuming default is 0 for invalid sides
}

TEST(DieTest, InvalidValue) {
    Die die(6);
    die.Set(7); // Invalid value
    EXPECT_NE(die.GetValue(), 7); // Value should not be set to invalid
}

TEST(DieTest, Randomness) {
    Die die(6);
    int count[7] = {0}; // Count occurrences of each side
    for (int i = 0; i < 1000; ++i) {
        die.Roll();
        count[die.GetValue()]++;
    }
    for (int i = 1; i <= 6; ++i) {
        EXPECT_GT(count[i], 0); // Each side should appear at least once
    }
}

TEST(DieTest, RandomnessDistribution) {
    Die die(6);
    int count[7] = {0}; // Count occurrences of each side
    for (int i = 0; i < 10000; ++i) {
        die.Roll();
        count[die.GetValue()]++;
    }
    for (int i = 1; i <= 6; ++i) {
        EXPECT_GT(count[i], 1000); // Each side should appear at least 1000 times
    }
}

TEST(DieTest, RandomnessUniformity) {
    Die die(6);
    int count[7] = {0}; // Count occurrences of each side
    for (int i = 0; i < 10000; ++i) {
        die.Roll();
        count[die.GetValue()]++;
    }
    for (int i = 1; i <= 6; ++i) {
        EXPECT_NEAR(count[i], 1666.67, 200); // Each side should be close to uniform distribution
    }
}