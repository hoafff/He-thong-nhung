/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Implementation file for the C-programming code that calculates some statistics.
 *
 *  1. main()             - The main entry point for the program.
 *  2. print_statistics() - A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *  3. print_array()      - Given an array of data and a length, prints the array to the screen.
 *  4. find_median()      - Given an array of data and a length, returns the median value.
 *  5. find_mean()        - Given an array of data and a length, returns the mean.
 *  6. find_maximum()     - Given an array of data and a length, returns the maximum.
 *  7. find_minimum()     - Given an array of data and a length, returns the minimum.
 *  8. sort_array()       - Given an array of data and a length, sorts the array from largest to smallest.  
 *                          (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value.)
 *
 * @author Renato Soriano
 * @date 03/10/2022
 *
 */

#include "../include/common/stats.h"

/*
// Size of the Data Set 
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  // Other Variable Declarations 
  unsigned char minimum = 0;
  unsigned char maximum = 0;
  unsigned char mean = 0;
  unsigned char median = 0;

  // Statistics and Printing Functions 

  printf("\nArray before sorting: \n");
  print_array(test, SIZE);

  sort_array(test, SIZE);
  printf("\nArray after sorting: \n");
  print_array(test, SIZE);

  minimum = find_minimum(test, SIZE);
  maximum = find_maximum(test, SIZE);
  median = find_median(test, SIZE);
  mean = find_mean(test, SIZE);

  print_statistics(minimum, maximum, mean, median);

  printf("\n");

  return 0;

}
*/

/* Implementation and Functions Definitions */

void print_statistics(unsigned char minimum, unsigned char maximum, unsigned char mean, unsigned char median){
  
  PRINTF("\nThe minimum is: %d \n", minimum);
  PRINTF("\nThe maximum is: %d \n", maximum);
  PRINTF("\nThe mean is: %d \n", mean);
  PRINTF("\nThe median is: %d \n", median);

}

void print_array(unsigned char * array, unsigned int count){

  /* The array will print only if the user defines "VERBOSE" in the command line */
  #ifdef VERBOSE

  if(array == NULL){
    PRINTF("Please Enter a valid input\n");
    return;
  }

  if(count <= 0){
    PRINTF("The array is empty...\n");
    return;
  }

  for(unsigned int i = 0; i < count; i++){
    if(i % 8 == 0){
      PRINTF("\n");
    }
    PRINTF("%d \t", array[i]);
  }

  PRINTF("\n");

  #endif
}

unsigned char find_median(unsigned char * array, unsigned int count){
  
  if(array == NULL){
    PRINTF("Please Enter a valid input\n");
    return -1;
  }

  if(count <= 0){
    PRINTF("The array is empty...\n");
    return -1;
  }

  if((count % 2) == 0 ){
    return (array[count/2]);
  }
  else{
    return ((array[count/2] + array[count/2]+1) / 2);
  }

}

unsigned char find_mean(unsigned char * array, unsigned int count){
  
  unsigned int sum = 0;

  if(array == NULL){
    PRINTF("Please Enter a valid input\n");
    return -1;
  }

  if(count <= 0){
    count = 1;
  }

  for(unsigned int i = 0; i < count; i++){
    sum = sum + array[i];
  }
 
  return (sum / count);

}

unsigned char find_maximum(unsigned char * array, unsigned int count){
  
  unsigned int max;

  if(array == NULL){
    PRINTF("Please Enter a valid input\n");
    return -1;
  }

  if(count <= 0){
    PRINTF("The array is empty...\n");
    return -1;
  }

  max = array[0];
  
  for(unsigned int i = 0; i < count; i++){
    if(array[i] > max){
      max = array[i];
    }
  }

  return max;

}

unsigned char find_minimum(unsigned char * array, unsigned int count){

  unsigned int min;

  if(array == NULL){
    PRINTF("Please Enter a valid input\n");
    return -1;
  }

  if(count <= 0){
    PRINTF("The array is empty...\n");
    return -1;
  }

  min = array[0];

  for(unsigned int i = 0; i < count; i++){
    if(array[i] < min){
      min = array[i];
    }
  }

  return min;

}

void sort_array(unsigned char * array, unsigned int count){

  unsigned int temp;

  if(array == NULL){
    PRINTF("Please Enter a valid input\n");
    return;
  }

  if(count <= 0){
    PRINTF("The array is empty...\n");
    return;
  }

  for(unsigned int i = 0; i < count-1; i++){
    for(unsigned int k = 0; k < count-i-1; k++){
      if( array[k+1] > array[k] ){
        temp = array[k+1];
        array[k+1] = array[k];
        array[k] = temp;
      }
    }
  }

}
