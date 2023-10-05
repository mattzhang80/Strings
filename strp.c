/*String Module that uses pointers as much as possible*/
#include "str.h"

/* Get the length of a string. Does this by looping through a string 
until it reaches its end and uses a difference of pointers. Returns a 
numeric value. Code taken from assignment specs.*/
size_t Str_getLength(const char *pcSrc) {
    /* Pointer to the end of the string */
    const char *pcEnd;
    assert(pcSrc != NULL);
    pcEnd = pcSrc;
    /* Loop through source string until it reaches its end */
    while(*pcEnd != '\0') {
        pcEnd++;
    }
    /* Return the length of the string */
    return (size_t) (pcEnd - pcSrc);
}

/* Copy a string. Does this by looping through a string until it reaches 
its end and sets another string and its correlated char array indices to 
be equal. Returns a string. */
char *Str_copy(char *pcDest, const char *pcSrc) {
    /* Pointer to the end of the string */
    char *pcDestStart = pcDest;
    assert(pcSrc != NULL && pcDest != NULL);
    /* Loop through source string until it reaches its end */
    while((*pcDestStart++ = *pcSrc++) != '\0');
    /* Return the destination string */
    return pcDest;
}

/* Concatenate two strings together. Does this by looping through a 
string until it reaches its end and sets another string and its 
correlated char array indices to be equal. Returns a string. */
char *Str_concat(char *pcDest, const char *pcSrc) {
    /* Pointer to the end of the string */
    char *pcDestStart = pcDest;
    assert(pcSrc != NULL && pcDest != NULL);
    /* Loop through destination string until it reaches its end */
    while(*pcDestStart != '\0') {
        pcDestStart++;
    }
    /* Loop through source string until it reaches its end */
    while((*pcDestStart++ = *pcSrc++) != '\0');
    return pcDest;
} 

/* Compare two strings. Does this by looping through each string until 
either one reaches the end of the string or until the characters are 
not equal. Returns an integer. */
int Str_compare(const char *pcStr1, const char *pcStr2) {
    assert(pcStr1 != NULL && pcStr2 != NULL);
    /* Loop through both strings while they are equal */
    while(*pcStr1 == *pcStr2 && *pcStr1 != '\0') {
        pcStr1++;
        pcStr2++;
    }
    /* Return the difference between the two strings */
    return (int) (*pcStr1 - *pcStr2);
}

/* Search for a substring in a string. Does this by looping through the 
haystack string until it reaches its end and then looping through the 
needle string until it reaches its end and then looping through both 
strings while they are equal. Returns a string. */
char *Str_search(const char *pcHaystack, const char *pcNeedle) {
    /* Pointer to the end of the string */
    const char *pcHaystackCopy, *pcNeedleCopy;
    assert(pcHaystack != NULL && pcNeedle != NULL);
    /* Return the haystack if the needle is empty */
    if(*pcNeedle == '\0') {
        return (char*) pcHaystack;
    }
    /* Loop through haystack string until it reaches its end */
    while(*pcHaystack != '\0') {
        /* Set the pointers to the beginning of the strings */
        pcHaystackCopy = pcHaystack;
        pcNeedleCopy = pcNeedle;
        /* Loop through both strings while they are equal */
        while((*pcHaystackCopy == *pcNeedleCopy) && *pcNeedleCopy != '\0') {
            pcHaystackCopy++;
            pcNeedleCopy++;
        }
        /* Return the haystack if the needle is empty */
        if (*pcNeedleCopy == '\0') {
            return (char *) pcHaystack;
        }
        pcHaystack++;
    /* Return NULL if the needle is not found */
    return NULL;
    }
}