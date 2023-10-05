/*Interface for string functions*/
#ifndef STR_H
#define STR_H
/*Include necessary libraries*/
#include <stddef.h>
#include <assert.h>
/*Get the length of a string.*/
size_t Str_getLength(const char pcSrc[]);
/*Create a new string that is a copy of an existing string.*/
char *Str_copy(char pcDest[], const char pcSrc[]);
/*Concatenate two strings together.*/
char *Str_concat(char pcDest[], const char pcSrc[]);
/*Compare two strings.*/
int Str_compare(const char pcStr1[], const char pcStr2[]);
/*Search for a substring in a string.*/
char *Str_search(const char pcHaystack[], const char pcNeedle[]);
#endif