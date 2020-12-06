/* SYSC 2006 Winter 2019 Lab 3. 

 * Incomplete implementations of the functions that are to be
 * coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "exercises.h"

/* Exercise 1. */

/* Return the average magnitude of the n doubles in x[]. 
 * This function assumes that parameter n is >= 1.
 */
double avg_magnitude(double x[], double n)
{
	double avg_mag = 0;

	for(int i =0; i<n; i++){
		avg_mag += fabs(x[i]);
	}
	
    return (avg_mag/n);
}

/* Exercise 2. */

/* Return the average power of the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_power(double x[], double n)
{
	double avg_pow = 0;

	for(int i =0; i<n; i++){
		avg_pow += pow(fabs(x[i]),2);
	}
	
    return (avg_pow/n);
    
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double max(double arr[], int n)
{
   int max = arr[0];
   
   for(int i  = 1; i  < n; i++){	
		if(arr[i]>max){
		
			max = arr[i];
		}	
   }
	return max;
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double min(double arr[], int n)
{
   int min = arr[0];
   
   for(int i  = 1; i  < n; i++){	
		if(arr[i]<min){
		
			min = arr[i];
		}	
   }
   return min;
}

/* Exercise 5. */

/* Normalize the n doubles in x[]. 
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in x[] are different.
 */
void normalize(double x[], int n)
{
	double min_x = min(x,n);
	double max_x = max(x,n);

	for(int i = 0;i < n; i++){
		x[i] = (x[i] - min_x)/(max_x - min_x);
	}

}
