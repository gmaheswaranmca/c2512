//Prerequisites: sudo apt-get install libgtest-dev
#include <gtest/gtest.h>
#include "../LibSun/Headers/Gcd.h"
#include "../LibSun/Headers/Arithmetic.h"

// Sample test for Gcd function
TEST(GcdTest, PositiveNumbers) {
    EXPECT_EQ(findGCD(12, 18), 6);
    EXPECT_EQ(findGCD(100, 25), 25);
}

// Sample test for Arithmetic addition
TEST(ArithmeticTest, AddNumbers) {
    EXPECT_EQ(findSum(10, 5), 15);
    EXPECT_EQ(findSum(-10, 20), 10);
}

// Main function to run tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
