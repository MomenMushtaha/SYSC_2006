/* SYSC 2006 Winter 2019 Lab 4 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "exercises.h"

/* Exercise 1 */

void print_array(int arr[], int n)
{
	int i = 0;
	while(i<n)
	{
		printf("This function should print the first %d elements of arr\n", (arr[i]));
    	//printf("This function should print the first %d elements of arr\n" , n);
		i = i + 1;
	}
}

/* Exercise 2. */

void rotate_left(int arr[], int n)
{
	int x = arr[0];
	int i =0;
	while(i <= (n - 1))
	{
		if(i == (n - 1))
		{
			arr[n - 1] = x;
		}
		else
		{
			arr[i] = arr[i + 1];
			
		}
	i = i + 1;
	}

}

/* Exercise 3. */

void reverse(int arr[], int n)
{
	int y = 0;
	int x = 0;
	int i = 0;
	while( i <= ((n - 1)/2))
	{
		x = arr[(n - 1) - i];
		y = arr[i];
		arr[(n - 1) - i] = y;
		arr[i] = x;
		i = i + 1;
	}
}


/* Extra-practice exercises. */

/* Exercise 4. */

void ten_run(int arr[], int n)
{
	int i = 0;
	while( i <= (n - 1))
	{
		if ((arr[i] > 9) | (arr[i] == 0))
		{
			arr[i] = arr[i];
			if (arr[i + 1] < 10)
			{
				arr[i + 1] = arr[i];
			}
		}
		else
		{
			arr[i] = arr[i];
		}
		i = i + 1;
	}	
}

/* Exercise 5. */

void without_tens(int arr[], int n)
{
	int x, y =0;
	int i = 0;
	while( i <= (n - 1))
	{
		if (arr[i] == 10)
		{
			arr[i] = 0;
			if (arr[i + 1] != 0)
			{
			for(int j = 0; (arr[n- j] != 0 ); j += 1)
			{
				x = arr[i+1];
				y = arr[i];
				arr[i -1] = y;
				arr[i] = x;
			}
			}
		}
		else
		{
			arr[i] = arr[i];
		}
		i = i + 1;
	}
}

