#include "shell.h"

/**
* s1: str 1
* s2: str 2
* str_concat - conc str 1 + str 2
* Return: string a null terminated char
*/

char *str_concat(char const *s1, char const *s2)
{
size_t	len;
char	*new_str;

if (!s1 || !s2)
return (NULL);
len = _strlen(s1) + _strlen(s2);
new_str = malloc(len + 1);
if (new_str == NULL)
return (NULL);
new_str[0] = '\0';
_strcat(new_str, s1);
_strcat(new_str, s2);
new_str[len] = '\0';
return (new_str);
}

/**
* s: str
* len: chars len
* start: begin
* str_sub - decrease paragraph from string
* Return: null char terminated
*/

char *str_sub(char const *s, unsigned int start, size_t len)
{
size_t	i;
char	*sub_str;

sub_str = (char *)malloc(len + 1);
if (s == NULL || sub_str == NULL)
return (NULL);
i = 0;
while (len-- && s[start + i])
{
sub_str[i] = s[start + i];
i++;
}
sub_str[i] = '\0';
return (sub_str);
}

/**
* ap: str ary
* mem_free -  checkvalve array
* Return: void
*/
void mem_free(void **ap)
{
if (ap)
{
free(*ap);
*ap = NULL;
}
}

/**
* as:  string array
* str_free -  dump strings
* Return: void
*/
void str_free(char **as)
{
mem_free((void **)as);
}

