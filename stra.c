/*String Module that uses arrays as much as possible*/

#include <stdio.h>
#include <string.h> 
#include <assert.h>

size_t Str_getLength(const char pcSrc[])
{
   size_t uLength = 0;
   assert(pcSrc != NULL);
   while (pcSrc[uLength] != '\0')
      uLength++;
   return uLength;
}

/*Create a new string that is a copy of an existing string. */
char *Str_copy(char pcDest[], const char pcSrc[])
{
   size_t u = 0;
   assert(pcSrc != NULL && pcDest != NULL);
   while ((pcDest[u] = pcSrc[u]) != '\0') {
        u++;
    }
   return pcDest;
}

/*Concatenate two strings together. */
char *Str_concat(char pcDest[], const char pcSrc[])
{
    size_t u = 0, destLength = Str_getLength(pcDest);
    assert(pcSrc != NULL && pcDest != NULL);
    while (pcSrc[u] != '\0') {
        pcDest[destLength + u] = pcSrc[u];
        u++;
    }
    pcDest[destLength + u] = '\0';
    return pcDest;
}

/*Compare two strings. */
int Str_compare(const char pcStr1[], const char pcStr2[])
{
   size_t u = 0;
   assert(pcStr1 != NULL && pcStr2 != NULL);
   while (pcStr1[u] == pcStr2[u]) {
        if (pcStr1[u] == '\0') 
            return 0; 
        u++;
    }
    return (int) (pcStr1[u] - pcStr2[u]);
}

/*Search for a substring in a string. */
const char *Str_search(const char pcHaystack[], const char pcNeedle[]) 
{
   size_t u, u2;
   assert(pcHaystack != NULL && pcNeedle != NULL);
    if(pcNeedle[0] == '\0')
        return pcHaystack;
   for (u = 0; pcHaystack[u] != '\0'; u++) {
      for (u2 = 0; pcNeedle[u2] != '\0'; u2++) {
         if (pcHaystack[u + u2] != pcNeedle[u2])
            break;
      }
      if (pcNeedle[u2] == '\0')
         return pcHaystack + u;
   }
   return NULL;
}