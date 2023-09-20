#include "shell.h"

/**
* input_str: User's input
* remove_comment - removes a comment from the input string
* Return: pointer
*/
char *remove_comment(char *input_str)
{
char *str_no_comments = input_str;

if (*input_str == '#')
{
*input_str = '\n';
*(input_str + 1) = '\0';
}
while (input_str && *input_str)
{
if (*input_str == '#' && *(input_str - 1) == ' ')
{
*(input_str - 1) = '\n';
*input_str = '\0';
break;
}
input_str++;
}
return (str_no_comments);
}

