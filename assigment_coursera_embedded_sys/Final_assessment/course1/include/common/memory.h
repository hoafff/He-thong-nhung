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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 * @modified Renato Soriano
 * @date March 27, 2022
 * 
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

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
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Copies bytes from the source to the destination.
 *
 * Given two pointers to a char data set, this will copy bytes
 * from the source to the destination. The behavior is undefined if there
 * is overlap of source and destination. Copy should still occur, but will
 * likely corrupt the data.
 *
 * @param src Pointer to source location.
 * @param dst Pointer to destination location.
 * @param length Length of bytes to copy from the source to the destination.
 *
 * @return Pointer to the destination location.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

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
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Sets bytes of memory source location with a zero.
 *
 * Given pointer to source memory location, this will set bytes in the
 * source memory location with zero.
 *
 * @param src Pointer to source memory location.
 * @param length Length of bytes of the source memory location.
 *
 * @return Pointer to the source memory location.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

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
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocates dynamic memory.
 *
 * Given number of words to be allocated in dynamic memory.
 * 
 * @param length Length of bytes of the source memory location.
 *
 * @return Pointer to the source memory location.
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Frees memory allocation
 *
 * Given pointer to memory location, this function will free this dynamic memory allocation.
 *
 * @param src Pointer to source memory location
 *
 * @return void.
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
