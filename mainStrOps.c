#include "shell.h"

/**
* string length - length of a str
* Return: length
*/
int string_length(const char *str)
{
int len = 0;

if (str == NULL)
return (0);

while (str[len])
len++;
return (len);
}

/**
* src:  ARY
* Return: pointer
*/

char *string_copy(const char *src)
{
Char *dest;
size_t index;

index = 0;
dest = (char *)malloc(sizeof(char) * string_length(src) + 1);
if (!dest)
return (NULL);
while (src[index])
{
dest[index] = src[index];
index++;
}
dest[index] = '\0';
return (dest);
}

/**
* str1: str1
* str2: str
* compare_n_chars - chars
* Return: 0 if it pass; otherwise  point
*/
int	compare_n_chars(const char *str1, const char *str2, size_t n)
{
size_t index;

index = 0;
while (index < n && str1 && str2 && str1[index] && str2[index] &&
(unsigned char)str1[index] == (unsigned char)str2[index])
index++;
if (index == n)
return (0);
return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}

/**
* string1: str1
* string2:str2
* Return: 0 if it pass; otherwise point
*/
int     compare_strings(const char *str1, const char *str2)
{
return (compare_n_chars(str1, str2, (size_t)-1));
}

/**
* integer_to_string - string
* Return: #no
*/
char *integer_to_string(int number)
{
int reversed_number = 0;
int count, num_digits = 0;
char *number_str = NULL;

if (number == 0)
num_digits = 1;
else
while (number > 0)
{
num_digits++;
reversed_number *= 10;
reversed_number += number % 10;
number /= 10;
}

number_str = malloc(sizeof(char) * (num_digits + 1));
if (number_str == NULL)
dispatch_error("Error: Allocating memory for number conversion failed");

for (count = 0; count < num_digits; count++)
{
number_str[count] = (reversed_number % 10) + '0';
reversed_number /= 10;
}
number_str[count] = '\0';

return (number_str);
}

