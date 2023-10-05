/*String Module that uses arrays as much as possible*/
#include "str.h"

/*Get the length of a string. Loops through string character by 
character, incrementing a numeric variable each time to track the 
length. Returns a numeric value.*/
size_t Str_getLength(const char pcSrc[])
{   
    /*Variable to track the length of the string*/
    size_t uLength = 0;
    assert(pcSrc != NULL);
    /*Loop through source string until it reaches its end*/
    while (pcSrc[uLength] != '\0')
        uLength++;
    /*Return the length of the string*/
    return uLength;
}

/*Create a new string that is a copy of an existing string. Does this by 
looping through a string until it reaches its end and sets another 
string and its correlated char array indices to be equal. Returns a 
string.*/
char *Str_copy(char pcDest[], const char pcSrc[])
{
    /*Variable to track the length of the string*/
    size_t u = 0;
    assert(pcDest != NULL && pcSrc != NULL);
    /*Loop through source string until it reaches its end*/
    for(u = 0; pcSrc[u] != '\0'; u++)
        pcDest[u] = pcSrc[u];
    pcDest[u] = '\0';
    /*Return the destination string*/
    return pcDest;
}

/*Concatenate two strings together. Does this by taking the length of 
the destination string and a loop to indicate the correlated index in 
the character array to concatenate the next character. 
Returns a string.*/
char *Str_concat(char pcDest[], const char pcSrc[])
{
    /*Variable to track the length of the string*/
    size_t u = 0, pcDestLength = Str_getLength(pcDest);
    assert(pcSrc != NULL && pcDest != NULL);
    /*Loop through source string until it reaches its end*/
    while (pcSrc[u] != '\0') {
        pcDest[pcDestLength + u] = pcSrc[u];
        u++;
    }
    pcDest[pcDestLength + u] = '\0';
    /*Return the destination string*/
    return pcDest;
}

/*Compare two strings. Does this by looping through each string until 
either one reaches the end of the string or until the characters are not 
equal. Returns an integer.*/
int Str_compare(const char pcStr1[], const char pcStr2[])
{
    /*Variable to track the length of the string*/
    size_t u = 0;
    assert(pcStr1 != NULL && pcStr2 != NULL);
    /*Loop through both strings while they are equal*/
    while (pcStr1[u] == pcStr2[u]) {
        if (pcStr1[u] == '\0') 
            return 0; 
        u++;
    }
    /*Return the difference between the two strings*/
    return (int) (pcStr1[u] - pcStr2[u]);
}

/*Search for a substring in a string. Does this by looping through the 
haystack string until it reaches its end. Then loops through the needle 
string until it reaches its end. If the needle is found, return the 
haystack. If the needle is not found, return NULL. Returns a string.*/
char *Str_search(const char pcHaystack[], const char pcNeedle[]) 
{
    /*Variables to track the length of the string*/
    size_t x, y;
    assert(pcHaystack != NULL && pcNeedle != NULL);
    size_t pcNeedleLength = Str_getLength(pcNeedle);
    /*If the needle is empty, return the haystack*/
    if(pcNeedleLength == 0)
        return (char) *pcHaystack;
    /*Loop through the haystack until it reaches its end*/
    for (x = 0; pcHaystack[x] != '\0'; x++) {
        for (y = 0; pcNeedle[y] != '\0'; y++) {
            if (pcHaystack[x + y] != pcNeedle[y])
                break;
        }
        /*Return the haystack if the needle is found*/
        if (pcNeedle[y] == '\0')
            return pcHaystack + x;
    }
    /*Return NULL if the needle is not found*/
    return NULL;
}