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
 * @file data.h
 * @brief Header File that contains declarations and prototypes of data.c
 *
 * The header file that contains the declarations of some very basic data manipulation.
 * 
 * @author Renato Soriano
 * @date March 26, 2022
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdio.h>
#include <stdint.h>
#include "memory.h"

/******************************************************************************
 *                             FUNCTION DECLARATION                           *
 ******************************************************************************/

/**
 * @brief Converts data from a standard integer type into an ASCII string. 
 *
 * Given a number, base of the number, and pointer to a char data set,
 * this will convert the value of the data using the base of the number into a 
 * string and store it address of it in the pointer.
 *
 * @param data Signed integer number to be converted.
 * @param ptr Pointer to character to store the converted data in it.
 * @param base Base to convert to.
 *
 * @return Length of the converted data.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief Converts data back from an ASCII represented string into an integer type.
 *
 * Given a string, digits in the string, and pointer to a char data set,
 * this will convert the value of the string using the base into an
 * integer and return the converted data.
 *
 * @param ptr Pointer to character to store the converted data in it.
 * @param digits Number of digits in the string.
 * @param base Base to convert to.
 *
 * @return Converted 32-bit signed integer data.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */