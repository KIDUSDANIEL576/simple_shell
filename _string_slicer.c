#include "shell.h"

/* TOKEN_POINTER */

static char *TOKEN_POINTER = "";
static int NO_INIT_TOKEN_POINTER = 1;

/* help func */

int check_delimiter(char c, char *delimiter);

/**
* delimiter: string will be split here
* string: Str to be split
*
* string_tokenizer - Splits a string into tokens
* Return:  tkn in str
*/

char *string_tokenizer(char *string, char *delimiter)
{

char *current_position;
char *token_start = NULL;

if (NO_INIT_TOKEN_POINTER == 1)
{

TOKEN_POINTER = NULL;
NO_INIT_TOKEN_POINTER = 0;

}

if ((string == NULL && TOKEN_POINTER == NULL) || (string != NULL && string[0] == '\0'))
return (NULL);

if (string != NULL)
TOKEN_POINTER = string;

for (current_position = TOKEN_POINTER; *current_position != '\0'; current_position++)
{

if (!check_delimiter(*current_position, delimiter))
{
token_start = current_position;
while (*current_position != '\0' && !check_delimiter(*current_position, delimiter))
	current_position++;

TOKEN_POINTER = current_position + 1;
if (*current_position == '\0')
	TOKEN_POINTER = current_position;
*current_position = '\0';

return (token_start);
}
}

return (NULL);
}

/**
* c: check Chars
* delimiter: assign of characters as a  delimiter
* check_delimiter - Checks if a char is a delimiter or not
* Return: if c is a delimiter print 1  otherwise print 0
*/

int check_delimiter(char c, char *delimiter)
{

while (*delimiter != '\0')

{
if (c == *delimiter)
return (1);

delimiter++;
}

return (0);

}

