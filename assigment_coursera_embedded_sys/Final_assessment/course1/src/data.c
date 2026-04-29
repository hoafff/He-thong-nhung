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
 * @file data.c
 * @brief Basic data manipulation operations
 *
 * This implementation file provides an abstraction of converting data from 
 * integer to string and vice versa via function calls.
 * 
 * @author Renato Soriano
 * @date March 27, 2022
 * 
 */

#include "../include/common/data.h"

/******************************************************************************
 *                             FUNCTION DEFINITIONS                           *
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
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
  uint8_t length = 0;
  uint16_t reminder;
  uint8_t isNegative = 0;

  /* Handle 0 explicity, otherwise empty string is printed. */
  if(data == 0)
  {
    *(ptr+length) = '0';
    ++length;
    *(ptr+length) = '\0';
    ++length;
    return length;
  }

  /* Negative number should handle only in base 10, otherwise number 
     should considered as unsigned number, but this will fail the test as 
     it passes the number in base 16 as negative number. */
  if(data < 0)
  {
    isNegative = 1;
    data = -data;
  }

  /* Process individual digits. */
  while(data != 0){
    reminder = data % base;
    *(ptr+length) = (reminder > 9)? ((reminder-10) + 'a') : (reminder + '0');
    length++;
    data = data/base;
  }

  /* If number is negative, append '-'. */
  if(isNegative)
  {
    *(ptr+length) = '-';
    ++length;
  }

  ++length;

  *(ptr+length) = '\0'; /* Append string terminator. */

  my_reverse(ptr, length-1);  /* Reverse the string. */

  return length;
}

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
 * @return Converted data.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  int8_t sign = 1;  /* Initialize the sign as positive. */
  uint8_t index;
  int32_t result = 0;

  /* If the number is negative, then update the sign. */
  if(*ptr == '-'){
    sign = -1; 
    ++ptr;
    --digits; 
  }

  /* Decrement the number of digits to avoid process the null character '\0'. */
  --digits; 

  /* Iterate through all digits and update the result. */
  for(index = 0; index < digits; index++){
    result = (result * base) + (*ptr - '0');
    ++ptr;
  }

  return (sign * result); /* Return result with sign. */
}