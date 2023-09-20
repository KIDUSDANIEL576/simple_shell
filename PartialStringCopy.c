#include "shell.h"

/**
* source: The string to be copied
* destination: The string source to be copied
* copy_string_n - Copies a string up to n characters
* num: #nu characters to copy from source
* Return: destination pointer
*/

char *copy_string_n(char *destination, char *source, int num)
{

int counter = 0;
char *beginning = destination;

while (*source != '\0' && counter < num)

{

*(beginning++) = *(source++);
counter++;
}

while (counter < num)

{

*(beginning++) = '\0';
counter++;
}

return (destination);

}

