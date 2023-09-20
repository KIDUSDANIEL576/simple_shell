#include "shell.h"

/**
* src: Source string
* copy: Pointer to the copy
* string_copy - Duplicates the string from src to copy
* Return: Pointer to copy
*/


char *string_copy(char *copy, char *src)
{
char *pointer;

pointer = copy;

while (*src != '\0')

{

*pointer = *src;
pointer++;
src++;

}

*pointer = '\0';

return (copy);
}

