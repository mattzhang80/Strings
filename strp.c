/*String Module that uses pointers as much as possible*/
#include "str.h"
#include <stddef.h>
#include <assert.h>

/* Get the length of a string. */
size_t Str_getLength(const char *pcSrc) {
    const char *pcEnd;
    pcEnd = pcSrc;
    assert(pcSrc != NULL);
    
    while(*pcEnd != '\0') {
        pcEnd++;
    }
    return (size_t) (pcEnd - pcSrc);
}

/* Copy two strings. */
char *Str_copy(char *pcDest, const char *pcSrc) {
    char *dest = pcDest;
    assert(pcSrc != NULL && pcDest != NULL);
    while((*dest++ = *pcSrc++) != '\0');
    return pcDest;
}

/* Concatenate two strings together. */
char *Str_concat(char *pcDest, const char *pcSrc) {
    char *dest = pcDest;
    assert(pcSrc != NULL && pcDest != NULL);
    while(*dest != '\0') {
        dest++;
    }
    while((*dest++ = *pcSrc++) != '\0');
    return pcDest;
} 

/* Compare two strings. */
int Str_compare(const char *pcStr1, const char *pcStr2) {
    assert(pcStr1 != NULL && pcStr2 != NULL);
    while(*pcStr1 == *pcStr2) {
        if(*pcStr1 == '\0') {
            return 0;
        }
        pcStr1++;
        pcStr2++;
    }
    return (int) (*pcStr1 - *pcStr2);
}

/* Search for a substring in a string. */
const char *Str_search(const char *pcHaystack, const char *pcNeedle) {
    const char *haystack = pcHaystack;
    const char *needle = pcNeedle;
    assert(pcHaystack != NULL && pcNeedle != NULL);
    if(*needle == '\0') {
        return pcHaystack;
    }
    while(*haystack != '\0') {
        if(*haystack == *needle) {
            const char *h = haystack;
            const char *n = needle;
            while(*h == *n && *n != '\0') {
                h++;
                n++;
            }
            if(*n == '\0') {
                return haystack;
            }
        }
        haystack++;
    }
    return NULL;
}
