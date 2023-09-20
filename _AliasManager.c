#include "shell.h"

static int alias_head_not_initialized = 1;
static list_t *head_of_alias;

/**
* get_head_of_alias - head_of_alias pointer
*
* Return: leads  to head_of_alias variable
*/

list_t **get_head_of_alias()
{
if (alias_head_not_initialized == 1)
{
head_of_alias = NULL;
alias_head_not_initialized = 0;
}
return (&head_of_alias);
}

/**
* pair_alias: String as alias arg input
* check_set_alias - Checks if the alias is set an alias
* Return: 1 if true, 0 if false
*/

int check_set_alias(char *pair_alias)
{
int index;

/* Check for the '=' sign */
/* the '=' sign shouldn't at index 0 */

for (index = 1; pair_alias[index] != '\0'; index++)
if (pair_alias[index] == '=')
return (1);

return (0);
}

/**
* pair_alias: String in name=value
* add_or_update_alias – add//updates alias
*/
void add_or_update_alias(char *pair_alias)
{
char buffer_tmp[250];
int first_eq, last_eq;
list_t *current_node;
list_t **address_of_alias = get_head_of_alias();

/* Find 1st '='  */
for (first_eq = 1; pair_alias[first_eq] != '\0'; first_eq++)
if (pair_alias[first_eq] == '=')
break;

/* duplicate text before  '=' */
strncpy(buffer_tmp, pair_alias, first_eq);
buffer_tmp[first_eq] = '\0';

/* Append ‘=’*/
strcat(buffer_tmp, "='");

/* search last eq in case of putting '=' sequentially */
for (last_eq = first_eq; pair_alias[last_eq] != '\0'; last_eq++)
if (pair_alias[last_eq] != '=')
break;

/* duplicate the 2nd part of the alias */
_strcat(buffer_tmp, &pair_alias[last_eq]);
_strcat(buffer_tmp, "'");

/* Add alias to the list */

for (current_node = *address_of_alias; current_node != NULL; current_node = current_node->next)
if (strncmp(current_node->str, pair_alias, first_eq) == 0 &&
(current_node->str)[first_eq] == '=')
{ /* Update already existing alias */
free(current_node->str);
current_node->str strdup(buffer_tmp);
return;
}

/* put new alias */
append_node_end(address_of_alias, buffer_tmp);
}

/**
* address_out: Pointers the head
* evaluate_alias_input - checks what to do
* commands: Ary cmd
* Return: -1 if it fails ,0 if it passes
*/
int evaluate_alias_input(char **commands, list_t **address_out)
{
int index, length, is_an_alias;
int status_code = 0;
list_t *current_node;
list_t **address_of_alias = get_head_of_alias();

set_process_exit_code(0);
for (index = 1; commands[index] != NULL; index++)
{
is_an_alias = 0;
length = strlen(commands[index]);

/* Checks user who are  trying to print */

for (current_node = *address_of_alias; current_node != NULL; current_node = current_node->next)
{
if (_strncmp(current_node->str, commands[index], length) == 0 && (current_node->str)[length] == '=')

is_an_alias = 1;
add_node_end(address_out, current_node->str);
break;
}
}
if (is_an_alias)
continue;

if (check_set_alias(commands[index]))
	add_or_update_alias(commands[index]);
else /* Print errors */
{
status_code = -1;
set_process_exit_code(1);
EchoShell("alias: ");
_EchoShell(commands[index]);
_EchoShell(" not found\n");
}
}

return (status_code);


/**
* process_aliases - Handle alias replacement
* @commands: Arrays of commands
*/

void process_aliases(char **commands)
{
list_t *current_node;
list_t **address_of_alias = get_head_of_alias();
int length_cmd = _strlen(commands[0]);
char *string;
char buffer_tmp[250];
int index, length_of_alias = 0;

if (commands[0] == NULL)
return;

/* buffer */
for (index = 0; index < 250; index++)
buffer_tmp[index] = '\0';

/* Search alias */
for (current_node = *address_of_alias; current_node != NULL; current_node = current_node->next)
{
string = current_node->str;
if (_strncmp(commands[0], string, length_cmd) == 0 && string[length_cmd] == '=')
{ /* alias command */
length_of_alias = _strlen(&string[length_cmd + 2]); /* +2 chars up  */
strncpy(buffer_tmp, &string[length_cmd + 2], length_of_alias - 1);
buffer_tmp[length_of_alias] = '\0';

/* command update*/
free(commands[0]);
commands[0] = duplicate_string(buffer_tmp);
break;
}
}
}

