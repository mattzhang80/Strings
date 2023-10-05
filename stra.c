/*String Module that uses arrays as much as possible*/
#include "str.h"

/*Get the length of a string pcSrc. Loops through string character by 
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

/*Create a new string from pcSrc that is a copy of an existing string 
into pcDest. Does this by looping through a string until it reaches its 
end and sets another string and its correlated char array indices to be 
equal. Returns a string.*/
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

/*Concatenate two strings, pcDest and pcSrc together. Does this by 
taking the length of the destination string and a loop to indicate the 
correlated index in the character array to concatenate the next 
character. Returns a string.*/
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

/*Compare two strings, pcStr1 and pcStr2. Does this by looping through 
each string until either one reaches the end of the string or until the 
characters are not equal. Returns an integer.*/
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

/*Search for a substring pcNeedle in a string pcHaystack. Does this by 
looping through the haystack string until it reaches its end. Then loops 
through the needle string until it reaches its end. If the needle is 
found, return the haystack. If the needle is not found, return NULL. 
Returns a string.*/
char *Str_search(const char pcHaystack[], const char pcNeedle[]) 
{
    /*Variables to track the length of the string*/
    size_t i, j;
    assert(pcHaystack != NULL && pcNeedle != NULL);
    int pcNeedleLength = Str_getLength(pcNeedle);
    /*If the needle is empty, return the haystack*/
    if(pcNeedleLength == 0)
        return (char*) pcHaystack;

    /*Loop through the haystack until it reaches its end*/
    for (i = 0; pcHaystack[i] != '\0'; i++) {
        for (j = 0; pcNeedle[j] != '\0'; j++) {
            if (pcHaystack[i + j] != pcNeedle[j])
                break;
        }
        /*Return the haystack if the needle is found*/
        if (j == pcNeedleLength)
            return (char*)&pcHaystack[i];
    }
    /*Return NULL if the needle is not found*/
    return NULL;
}