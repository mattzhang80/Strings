#include  <stdio.h>
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
   assert(pcSrc != NULL && pcDest != NULL);
   size_t u;
   for (u = 0; pcSrc[u] != '\0'; u++)
      pcDest[u] = pcSrc[u];
   pcDest[u] = '\0';
   return pcDest;
}

/*Concatenate two strings together. */
char *Str_concat(char pcDest[], const char pcSrc[])
{
   assert(pcSrc != NULL && pcDest != NULL);
   size_t destLength = Str_getLength(pcDest);
   size_t u;
   for (u = 0; pcSrc[u] != '\0'; u++)
      pcDest[destLength + u] = pcSrc[u];
   pcDest[destLength + u] = '\0';
   return pcDest;
}

/*Compare two strings. */
int Str_compare(const char pcStr1[], const char pcStr2[])
{
   assert(pcStr1 != NULL && pcStr2 != NULL);
   size_t u;
   while (pcStr1[u] == pcStr2[u]) {
        if (pcStr1[u] == '\0') 
            return 0; 
        u++;
    }
    return pcStr1[u] - pcStr2[u];
}

/*Search for a substring in a string. */
const char *Str_search(const char pcHaystack[], const char pcNeedle[])
{
   assert(pcHaystack != NULL && pcNeedle != NULL);
   size_t u;
   size_t uLength = Str_getLength(pcNeedle);
   for (u = 0; pcHaystack[u] != '\0'; u++)
   {
      if (Str_compare(pcHaystack + u, pcNeedle) == 0)
         return pcHaystack + u;
   }
   return NULL;
}