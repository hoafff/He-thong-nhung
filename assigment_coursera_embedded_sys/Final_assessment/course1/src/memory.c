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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 * 
 * @modified Renato Soriano
 * @date March 27, 2022
 *
 */

#include "../include/common/memory.h"

/***********************************************************
                    Function Definitions
***********************************************************/

/**
 * @brief Sets a value of a data array.
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array.
 * @param index Index into pointer array to set value.
 * @param value Value to write to the location.
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

/**
 * @brief Clears a value of a data array·
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array.
 * @param index Index into pointer array to set value.
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

/**
 * @brief Returns a value of a data array.
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array.
 * @param index Index into pointer array to set value.
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

/**
 * @brief Sets data array elements to a value.
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array.
 * @param value Value to write to the location.
 * @param size Number of elements to set to value.
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

/**
 * @brief Clears elements in a data array.
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array.
 * @param size Number of elements to set to zero.
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/**
 * @brief Moves bytes from the source to the destination.
 *
 * Given two pointers to a char data set, this will move bytes
 * from the source to the destination. The behavior should handle
 * overlap of source and destination. Copy should occur, with no data corruption.
 *
 * @param src Pointer to source location.
 * @param dst Pointer to destination location.
 * @param length Length of bytes to move from the source to the destination.
 *
 * @return Pointer to the destination location.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  uint8_t index;
  uint8_t buffer[length];

  for(index = 0; index < length; index++){
    *(buffer+index) = *(src+index);
  }

  for(index = 0; index < length; index++){
    *(dst+index) = *(buffer+index);
  }

  return dst;
}

/**
 * @brief Copies bytes from the source to the destination.
 *
 * Given two pointers to a char data set, this will move bytes
 * from the source to the destination. The behavior is undefined if there
 * is overlap of source and destination. Copy should still occur, but will
 * likely corrupt the data.
 *
 * @param src Pointer to source location.
 * @param dst Pointer to destination location.
 * @param length Length of bytes to move from the source to the destination.
 *
 * @return Pointer to the destination location.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  uint8_t index;

  for(index = 0; index < length; index++){
    *(dst+index) = *(src+index);
  }

  return dst;
}

/**
 * @brief Sets bytes of memory source location with a given value.
 *
 * Given pointer to source memory location, this will set bytes in the
 * source memory location with the given value.
 *
 * @param src Pointer to source memory location.
 * @param length Length of bytes of the source memory location.
 * @param value Value to be set in the source memory location.
 *
 * @return Pointer to the source memory location.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
  uint8_t index;

  for(index = 0; index < length; index++){
    *(src+index) = value;
  }

  return src;
}

/**
 * @brief Sets bytes of memory source location with zeros.
 *
 * Given pointer to source memory location, this will set bytes in the
 * source memory location with zeros.
 *
 * @param src Pointer to source memory location.
 * @param length Length of bytes of the source memory location.
 *
 * @return Pointer to the source memory location.
 */
uint8_t * my_memzero(uint8_t * src, size_t length){
  uint8_t index;

  for(index = 0; index < length; index++){
    *(src+index) = 0;
  }

  return src;
}

/**
 * @brief Reverses the order of all of the bytes in the source memory location.
 *
 * Given pointer to source memory location, this will reverse order of all of 
 * bytes in the source memory location.
 *
 * @param src Pointer to source memory location.
 * @param length Length of bytes of the source memory location.
 *
 * @return Pointer to the source memory location.
 */
uint8_t * my_reverse(uint8_t * src, size_t length){
  uint8_t index;
  uint8_t temp;
  uint8_t size = length/2;

  for(index = 0; index < size ; index++){
    temp = *(src+index);
    *(src+index) = *(src+length-index-1);
    *(src+length-index-1) = temp;
  }

  return src;
}

/**
 * @brief Allocates dynamic memory.
 *
 * Given number of word to be allocated in dynamic memory.
 * 
 * @param length Length of bytes of the source memory location.
 *
 * @return Pointer to the source memory location if successful, or a 
 *         Null Pointer if not successful.
 */
int32_t * reserve_words(size_t length){
  if(length > 0)
  {
    int32_t * ptr = (int32_t *)malloc(sizeof(int32_t) * length);
    return ptr;
  }else{
    return NULL;
  }
}

/**
 * @brief Frees the dynamic memory location.
 *
 * Given pointer to memory location, this function will free this dynamic memory location.
 *
 * @param src Pointer to source memory location.
 *
 * @return void.
 */
void free_words(uint32_t * src){
  free(src);
}