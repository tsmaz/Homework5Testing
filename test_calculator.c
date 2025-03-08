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

void test_subtract_positive_numbers(void) 
{
    TEST_ASSERT_EQUAL(1, subtract(5,4)); // We expect 5 - 4 to be 1
}

void test_subtract_negative_numbers(void) 
{
    TEST_ASSERT_EQUAL(-2, subtract(-5,-3)); // We expect -5 - -3 to be -2
}

void test_subtract_positive_and_negative_numbers(void) 
{
    TEST_ASSERT_EQUAL(8, subtract(5,-3)); // We expect 5 - -3 to be 8
}

void test_subtract_zero(void) 
{
    TEST_ASSERT_EQUAL(5, subtract(5,0)); // We expect 5 - 0 to be 5
}

void test_subtract_overflow(void)
{
    int result = subtract(INT_MIN, 1);
    TEST_ASSERT_TRUE(result > 0);
}

void test_subtract_underflow(void)
{
    int result = subtract(INT_MAX, -1);
    TEST_ASSERT_TRUE(result < 0);
}

int main(void) 
{
    UNITY_BEGIN();

    // Testing add function
    RUN_TEST(test_add_positive_numbers); 
    RUN_TEST(test_add_negative_numbers); 
    RUN_TEST(test_add_positive_and_negative_numbers); 
    RUN_TEST(test_add_zero); 
    RUN_TEST(test_add_overflow); 
    RUN_TEST(test_add_underflow); 

    // Testing subtract function
    RUN_TEST(test_subtract_positive_numbers);
    RUN_TEST(test_subtract_negative_numbers);
    RUN_TEST(test_subtract_positive_and_negative_numbers);
    RUN_TEST(test_subtract_zero);
    RUN_TEST(test_subtract_overflow);
    RUN_TEST(test_subtract_underflow);

    return UNITY_END();
}