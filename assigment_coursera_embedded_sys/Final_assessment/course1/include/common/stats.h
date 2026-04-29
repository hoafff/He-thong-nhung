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
 * @file stats.h 
 * @brief Header file with declarations and prototypes of stats.c.
 *
 * The header file that contains all functions prototypes that used 
 * to calculate the statistics. 
 *
 * @author Renato Soriano 
 * @date 03/10/2022 
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stdio.h>
#include "platform.h"

/**
 * @brief Prints the statistics of a set of data.
 *
 * This function takes mean, minimum, maximum, and median then prints these
 * values.
 * 
 * @param minimum The minimum number of the given array.
 * @param maximum The maximum number of the given array.
 * @param mean The mean of the given array.
 * @param median The median of the given array.
 *
 * @return void.
 */
void print_statistics(unsigned char minimum, unsigned char maximum, unsigned char mean, unsigned char median);


/**
 * @brief Prints the contents of a given array.
 *
 * This function takes an array and the size of it, then print it on the screen.
 * 
 * @param array Pointer to a data set.
 * @param count Number of items in data set.
 *
 * @return void.
 */
void print_array(unsigned char * array, unsigned int count);


/**
 * @brief Finds the median of the given array
 *
 * This function takes the given array and finds its median.
 * 
 * @param array Pointer to a data set
 * @param count Number of items in data set
 *
 * @return median The median value of the given array.
 */
unsigned char find_median(unsigned char * array, unsigned int count);

/**
 * @brief Finds the mean of the given array.
 *
 * This function takes the given array and finds its mean.
 * 
 * @param array Pointer to a data set.
 * @param count Number of items in data sets.
 *
 * @return mean The mean value of the given array.
 */
unsigned char find_mean(unsigned char * array, unsigned int count);

/**
 * @brief Finds the maximum of the given array.
 *
 * This function takes the given array and finds its maximum.
 * 
 * @param array Pointer to a data set.
 * @param count Number of items in data sets.
 *
 * @return maximum The maximum value of the given array.
 */
unsigned char find_maximum(unsigned char * array, unsigned int count);

/**
 * @brief Finds the minimum of the given array.
 *
 * This function takes the given array and finds its minimum.
 * 
 * @param array Pointer to a data set.
 * @param count Number of items in data sets.
 *
 * @return minimum The minimum value of the given array.
 */
unsigned char find_minimum(unsigned char * array, unsigned int count);

/**
 * @brief Sorts the given array from the largest to smallest.
 *
 * This function takes a set of numbers and sorts the data in it from the 
 * largest to the smallest.
 * 
 * @param array Pointer to a data set.
 * @param count Number of items in data sets.
 *
 * @return void.
 */
void sort_array(unsigned char * array, unsigned int count);

#endif /* __STATS_H__ */
