/* SYSC 2006 Winter 2019 Lab 2.
 *
 * Test harness - DO NOT MODIFY THIS FILE!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sput.h"
#include "exercises.h"

#define PI 3.14159265358979323846

/* By default, Pelles C generates "warning #2154: Unreachable code"
   and "warning #2130: Result of comparison is constant" when the 
   macros in sput.h are used. The following pragma directive disables the
   generation of these warnings.
 */
#pragma warn(disable: 2130 2154)

static void test_factorial(void)
{
    sput_fail_unless(factorial(0) == 1, "factorial(0) ==> 1");
    sput_fail_unless(factorial(1) == 1, "factorial(1) ==> 1");
    sput_fail_unless(factorial(2) == 2, "factorial(2) ==> 2");
    sput_fail_unless(factorial(3) == 6, "factorial(3) ==> 6");
    sput_fail_unless(factorial(4) == 24, "factorial(4) ==> 24");
}

static void test_ordered_subsets(void)
{
    sput_fail_unless(ordered_subsets(5, 1) == 5, "ordered_subsets(5, 1) ==> 5");
    sput_fail_unless(ordered_subsets(5, 2) == 20, "ordered_subsets(5, 2) ==> 20");
    sput_fail_unless(ordered_subsets(5, 3) == 60, "ordered_subsets(5, 3) ==> 60");
    sput_fail_unless(ordered_subsets(5, 4) == 120, "ordered_subsets(5, 4) ==> 120");
    sput_fail_unless(ordered_subsets(5, 5) == 120, "ordered_subsets(5, 5) ==> 120");
}

static void test_binomial(void)
{
    sput_fail_unless(binomial(5, 1) == 5, "binomial(5, 1) ==> 5");
    sput_fail_unless(binomial(5, 2) == 10, "binomial(5, 2) ==> 10");
    sput_fail_unless(binomial(5, 3) == 10, "binomial(5, 3) ==> 10");
    sput_fail_unless(binomial(5, 4) == 5, "binomial(5, 4) ==> 5");
    sput_fail_unless(binomial(5, 5) == 1, "binomial(5, 5) ==> 1");
}

static void test_cosine(void)
{
    printf("\n\nTesting cosine\n\n");

    printf("Calculating cosine of 0 radians\n");
    printf("Calling standard library cos function, result = %.8f\n", cos(0));
    printf("Calling cosine function.\n");
    for (int i = 1; i <= 7; i += 1) {
        printf("# terms = %d, result = %.8f\n", i, cosine(0, i));
    }
    printf("\n");

    printf("Calculating cosine of PI/4 radians\n");
    printf("Calling standard library cos function, result = %.8f\n", cos(PI / 4));
    printf("Calling cosine function\n");
    for (int i = 1; i <= 7; i += 1) {
        printf("# terms = %d, result = %.8f\n", i, cosine(PI / 4, i));
    }
    printf("\n");

    printf("Calculating cosine of PI/2 radians\n");
    printf("Calling standard library cos function, result = %.8f\n", cos(PI / 2));
    printf("Calling cosine function\n");
    for (int i = 1; i <= 7; i += 1) {
        printf("# terms = %d, result = %.8f\n", i, cosine(PI / 2, i));
    }
    printf("\n");

    printf("Calculating cosine of PI radians\n");
    printf("Calling standard library cos function, result = %.8f\n", cos(PI));
    printf("Calling cosine function\n");
    for (int i = 1; i <= 7; i += 1) {
        printf("# terms = %d, result = %.8f\n", i, cosine(PI, i));
    }
    printf("\n");
}

int main(void)
{
    sput_start_testing();

    sput_enter_suite("Exercise 1: factorial()");
    sput_run_test(test_factorial);

    sput_enter_suite("Exercise 2: ordered_subsets()");
    sput_run_test(test_ordered_subsets);

    sput_enter_suite("Exercise 3: binomial()");
    sput_run_test(test_binomial);
    sput_leave_suite();

    test_cosine();

    sput_finish_testing();
    return sput_get_return_value();
}
