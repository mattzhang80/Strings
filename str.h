/*Interface for string functions*/
#ifndef STR_H
#define STR_H

/*Include necessary libraries*/
#include <stddef.h>
#include <assert.h>

/*Get the length of a string pcSrc. Loops through string character by 
character, incrementing a numeric variable each time to track the 
length. Returns a numeric value.*/
size_t Str_getLength(const char pcSrc[]);

/*Create a new string from pcSrc that is a copy of an existing string 
into pcDest. Does this by looping through a string until it reaches its 
end and sets another string and its correlated char array indices to be 
equal. Returns a string.*/
char *Str_copy(char pcDest[], const char pcSrc[]);

/*Concatenate two strings, pcDest and pcSrc together. Does this by 
taking the length of the destination string and a loop to indicate the 
correlated index in the character array to concatenate the next 
character. Returns a string.*/
char *Str_concat(char pcDest[], const char pcSrc[]);

/*Compare two strings, pcStr1 and pcStr2. Does this by looping through 
each string until either one reaches the end of the string or until the 
characters are not equal. Returns an integer.*/
int Str_compare(const char pcStr1[], const char pcStr2[]);

/*Search for a substring pcNeedle in a string pcHaystack. Does this by 
looping through the haystack string until it reaches its end. Then loops 
through the needle string until it reaches its end. If the needle is 
found, return the haystack. If the needle is not found, return NULL. 
Returns a string.*/
char *Str_search(const char pcHaystack[], const char pcNeedle[]);

#endif