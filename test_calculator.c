#include "unity.h"
#include "calculator.h"

void setUp(void) 
{
    // Initialize any resources you may need before running the test
}

void tearDown(void) 
{
    // Free any resources that were allocated in setUp()
}

void test_add_positive_numbers(void) 
{
    TEST_ASSERT_EQUAL(10, add(5,4)); // We expect 2 + 3 to be 5
}

void test_add_negative_numbers(void) 
{
    TEST_ASSERT_EQUAL(-8, add(-5,-3)); // We expect -2 + -3 to be -5
}

void test_add_positive_and_negative_numbers(void) 
{
    TEST_ASSERT_EQUAL(2, add(5,-3)); // We expect 2 + -3 to be -1
}

void test_add_zero(void) 
{
    TEST_ASSERT_EQUAL(5, add(5,0)); // We expect 5 + 0 to be 5
}

void test_add_overflow(void)
{
    int result = add(INT_MAX, 1);
    TEST_ASSERT_TRUE(result < 0);
}

void test_add_underflow(void)
{
    int result = add(INT_MIN, -1);
    TEST_ASSERT_TRUE(result > 0);
}

int main(void) 
{
    UNITY_BEGIN();

    RUN_TEST(test_add_positive_numbers); // Run our test function
    RUN_TEST(test_add_negative_numbers); // Run our test function
    RUN_TEST(test_add_positive_and_negative_numbers); // Run our test function
    RUN_TEST(test_add_zero); // Run our test function
    RUN_TEST(test_add_overflow); // Run our test function
    RUN_TEST(test_add_underflow); // Run our test function

    return UNITY_END();
}