#include "shell.h"

/**
* str: input string
* find_char - string chr
* Return: ptr to the character
*/


char *find_char(const char *str, int ch)
{
size_t index;

index = 0;
while (str[index])
{
if (str[index] == ch)
return ((char *)&str[index]);
index++;
}
if (ch == '\0')
return ((char *)(&str[index]));
return (NULL);
}

/**
* str1: first str
* str2: second str
* Return: pointer to the resulting string
*/
char *concatenate_strings(char *str1, const char *str2)
{
return (concatenate_n_chars(str1, str2, -1));
}

/**
* str1: first string
* str2: second string
* n: number of characters from str2 to concatenate to str1
* concatenate_n_chars – concat  character str2 to str1
* Return: pointer to the resulting string
*/

char *concatenate_n_chars(char *str1, const char *str2, size_t n)
{
size_t i;
size_t j;

i = string_length(str1);
j = 0;
while (str2[j] && j < n)
str1[i++] = str2[j++];
str1[i] = '\0';
return (str1);
}

