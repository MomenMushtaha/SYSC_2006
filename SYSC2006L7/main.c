/* main.c - SYSC 2006 Winter 2019 Lab 7 Test Harness 
 *
 * Do not modify any code in this file.
 *
 * Tests last revised February 24, 2019.
 */

#include <stdlib.h>  // exit, malloc, free
#include <stdio.h>   // printf
#include "sput.h"

#include "array_list.h"

/* By default, Pelles C generates "warning #2154: Unreachable code"
   and "warning #2130: Result of comparison is constant" when the 
   macros in sput.h are used. The following pragma directive disables the
   generation of these warnings.
 */
#pragma warn(disable: 2130 2154)

static _Bool compare_arrays(int arr1[], int arr2[], int n)
{
    for (int i = 0; i < n; i = i + 1) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

static void test_intlist_construct(void)
{
    intlist_t *list = intlist_construct(10);
    sput_fail_unless(list->capacity == 10,
                     "list = intlist_construct(10),\n"
                     "verifying list capacity == 10");
    sput_fail_unless(list->size == 0,
                     "list = intlist_construct(10),\n"
                     "verifying list size == 0");
    sput_fail_unless(list->elems != NULL,
                     "list = intlist_construct(10),\n"
                     "verifying list->elems is not NULL");

    intlist_destroy(list);
}

static void test_intlist_print(void)
{
    printf("\nTesting intlist_print\n\n");

    intlist_t *list = intlist_construct(4);

    /* Print [] */

	list->size = 0;

    /* We can't assume that intlist_print is working, so we can't call it
     * to display the expected output!
     */
	printf("Expected output: []\n");
	printf("Actual output:   ");
	intlist_print(list);
	printf("\n\n");

    /* Print [1] */

	/* We can't assume intlist_append is working, so we have to initialize
	 * the list ourselves.
	 */
	list->elems[0] = 1;
	list->size = 1;

	printf("Expected output: [1]\n");
	printf("Actual output:   ");
	intlist_print(list);
	printf("\n\n");

    /* Print [1, 5, -3, 9] */

	list->elems[0] = 1;
	list->elems[1] = 5;
	list->elems[2] = -3;
	list->elems[3] = 9;
	list->size = 4;

	printf("Expected output: [1 5 -3 9]\n");
	printf("Actual output:   ");
	intlist_print(list);
	printf("\n\n");

    intlist_destroy(list);
}

static void test_intlist_append(void)
{
    _Bool appended;
    int expected[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    intlist_t *list = intlist_construct(10);

    appended = intlist_append(list, 1);

    sput_fail_unless(appended == true, 
                     "list = intlist_construct(10);\n"
		             "verifying intlist_append(list, 1) returns true");
    sput_fail_unless(compare_arrays(list->elems, expected, 1), 
		             "verifying list is [1]");
    sput_fail_unless(list->size == 1,
                     "verifying list size is 1");
    sput_fail_unless(list->capacity == 10,
                     "verifying list capacity == 10");


    appended = intlist_append(list, 3);
    sput_fail_unless(appended == true, 
                     "verifying intlist_append(list, 3) returns true");
    sput_fail_unless(compare_arrays(list->elems, expected, 2), 
                     "verifying list is [1 3]");
    sput_fail_unless(list->size == 2,
                     "verifying list size is 2");
    sput_fail_unless(list->capacity == 10,
                     "verifying list capacity == 10");


    intlist_destroy(list);


	list = intlist_construct(10);
       
	for (int i = 0; i < 9; i++) {
        appended = intlist_append(list, 2 * i + 1);
    }
    /* The list should now be [1, 3, 5, ..., 17], size == 9, capacity == 10 */

    appended = intlist_append(list, 19);
    sput_fail_unless(appended == true, 
                     "creating list [1 3 5 7 9 11 13 15 17],\n"
                     "verifying intlist_append(list, 19) returns true");
    sput_fail_unless(compare_arrays(list->elems, expected, 10), 
                     "verifying list is [1 3 5 7 9 11 13 15 17 19]");
    sput_fail_unless(list->size == 10,
                     "verifying list size is 10");
    sput_fail_unless(list->capacity == 10,
                     "verifying list capacity == 10");


    /* Now attempt to append an integer to a full list.*/

    appended = intlist_append(list, 21);
    sput_fail_unless(appended == false, 
                     "list is full\n"
                     "verifying intlist_append(list, 21) returns false");
    sput_fail_unless(compare_arrays(list->elems, expected, 10), 
                     "verifying list is [1 3 5 7 9 11 13 15 17 19]");
    sput_fail_unless(list->size == 10,
                     "verifying list size is 10");
    sput_fail_unless(list->capacity == 10,
                     "verifying list capacity == 10");

    intlist_destroy(list);
}

static void test_intlist_capacity(void)
{
    intlist_t *list = intlist_construct(10);

    sput_fail_unless(intlist_capacity(list) == 10, 
                     "list = intlist_construct(10),\n"
                     "verifying intlist_capacity(list) returns 10");

    /* Initialize list to [0, 2, 4, 6, 8] */
    for (int i = 0; i < 5; i++) {
        intlist_append(list, 2 * i);
    }

    /* Verify that appending integers doesn't change the list's capacity. */
   
    sput_fail_unless(intlist_capacity(list) == 10, 
                     "append 5 integers,\n"
                     "verifying intlist_capacity(list) returns 10");

    intlist_destroy(list);
}

static void test_intlist_size(void)
{
    intlist_t *list = intlist_construct(10);

    sput_fail_unless(intlist_size(list) == 0, 
                     "list = intlist_construct(10),\n"
                     "verifying intlist_size(list) returns 0");

    /* Initialize list to [0, 2, 4, 6, 8] */
    for (int i = 0; i < 5; i++) {
        intlist_append(list, 2 * i);
    }

    sput_fail_unless(intlist_size(list) == 5, 
                     "append 5 integers,\n "
                     "verifying intlist_size(list) returns 5");
  
    intlist_destroy(list);
}

static void test_intlist_get(void)
{
    intlist_t *list = intlist_construct(10);

    /* Initialize list to [0, 2, 4, 6, 8] */
    for (int i = 0; i < 5; i++) {
        intlist_append(list, 2 * i);
    }

    sput_fail_unless(intlist_get(list, 0) == 0,
                     "list = intlist_construct(10),\n"
                     "initialized list to [0 2 4 6 8],\n"
		             "verifying intlist_get(list, 0) returns 0");
    sput_fail_unless(intlist_size(list) == 5,
                     "verifying list size is 5");
    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity == 10");

    sput_fail_unless(intlist_get(list, 1) == 2,
                     "verifying intlist_get(list, 1) returns 2");
    sput_fail_unless(intlist_size(list) == 5,
                     "verifying list size is 5");
    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity == 10");

    sput_fail_unless(intlist_get(list, 2) == 4,
                     "verifying intlist_get(list, 2) returns 4");
    sput_fail_unless(intlist_size(list) == 5,
                     "verifying list size is 5");
    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity == 10");

    sput_fail_unless(intlist_get(list, 3) == 6,
                     "verifying intlist_get(list, 3) returns 6");
    sput_fail_unless(intlist_size(list) == 5,
                     "verifying list size is 5");
    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity == 10");

    sput_fail_unless(intlist_get(list, 4) == 8,
                     "verifying intlist_get(list, 4) returns 8");
    sput_fail_unless(intlist_size(list) == 5,
                     "verifying list size is 5");
    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity == 10");

    intlist_destroy(list);
}

static void test_intlist_set(void)
{
    intlist_t *list = intlist_construct(10);

    /* Initialize list to [0, 2, 4, 6, 8] */
    for (int i = 0; i < 5; i++) {
        intlist_append(list, 2 * i);
    }

    sput_fail_unless(intlist_set(list, 0, 1) == 0,
                     "list = intlist_construct(10),\n"
                     "initialized list to [0 2 4 6 8],\n"
		             "verifying intlist_set(list, 0, 1) returns 0");
    sput_fail_unless(intlist_get(list, 0) == 1,
                     "verifying list element 0 is now 1");
    sput_fail_unless(intlist_size(list) == 5,
                     "verifying list size is 5");
    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity == 10");

    sput_fail_unless(intlist_set(list, 1, 3) == 2,
                     "verifying intlist_set(list, 1, 3) returns 2");
    sput_fail_unless(intlist_get(list, 1) == 3,
                     "verifying list element 1 is now 3");
    sput_fail_unless(intlist_size(list) == 5,
                     "verifying list size is 5");
    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity == 10");

    sput_fail_unless(intlist_set(list, 2, 5) == 4,
                     "verifying intlist_set(2) returns 4");
    sput_fail_unless(intlist_get(list, 2) == 5,
                     "verifying list element 2 is now 5");
    sput_fail_unless(intlist_size(list) == 5,
                     "verifying list size is 5");
    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity == 10");

    sput_fail_unless(intlist_set(list, 3, 7) == 6,
                     "verifying intlist_set(list, 3, 7) returns 6");
    sput_fail_unless(intlist_get(list, 3) == 7,
                     "verifying list element 3 is now 7");
    sput_fail_unless(intlist_size(list) == 5,
                     "verifying list size is 5");
    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity == 10");

    sput_fail_unless(intlist_set(list, 4, 9) == 8,
                     "verifying intlist_set(list, 4, 9) returns 8");
    sput_fail_unless(intlist_get(list, 4) == 9,
                     "verifying list element 4 is now 9");
    sput_fail_unless(intlist_size(list) == 5,
                     "verifying list size is 5");
    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity == 10");

    intlist_destroy(list);
}

static void test_intlist_removeall(void)
{
    intlist_t *list = intlist_construct(10);

    /* Initialize list to [0, 2, 4, 6, 8] */
    for (int i = 0; i < 5; i++) {
        intlist_append(list, 2 * i);
    }
    intlist_removeall(list);

    sput_fail_unless(intlist_size(list) == 0,
                     "list = intlist_construct(10),\n"
		             "initialized list to [0 2 4 6 8],\n"
                     "intlist_removeall(list)\n"
                     "verifying list size is now 0");

    sput_fail_unless(intlist_capacity(list) == 10,
                     "verifying list capacity is 10");

    sput_fail_unless(list->elems != NULL,
                     "verifying list->elems is not NULL");

    intlist_destroy(list);
}

int main(void)
{
    sput_start_testing();

    sput_enter_suite("Exercise 1: intlist_construct()");
    sput_run_test(test_intlist_construct);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Remaining tests won't be run until intnode_construct "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 2: intlist_print()");
    sput_run_test(test_intlist_print);

    sput_enter_suite("Exercise 3: intlist_append()");
    sput_run_test(test_intlist_append);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Remaining tests won't be run until intnode_append "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 4: intlist_capacity()");
    sput_run_test(test_intlist_capacity);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Remaining tests won't be run until intnode_capacity "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 5: intlist_size()");
    sput_run_test(test_intlist_size);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Remaining tests won't be run until intnode_size "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 6: intlist_get()");
    sput_run_test(test_intlist_get);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Remaining tests won't be run until intnode_get "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 7: intlist_set()");
    sput_run_test(test_intlist_set);
    sput_leave_suite();

    if (sput_get_return_value() == EXIT_FAILURE) {
        printf("Remaining tests won't be run until intnode_set "
               "passes all tests.\n");
        sput_finish_testing();
        return sput_get_return_value();
    }

    sput_enter_suite("Exercise 8: intlist_removeall()");
    sput_run_test(test_intlist_removeall);

    sput_finish_testing();
    return sput_get_return_value();
}
