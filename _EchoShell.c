#include "shell.h"

/**
* output_string - Outputs a string
* @str: string output
*
* Return: The number of characters output
*/
int output_string(char *str)
{
int length = _strlen(str);

write(STDOUT_FILENO, str, length);

return (length);
}
