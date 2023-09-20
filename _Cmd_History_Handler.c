#include "shell.h"

/* variables */
static list_t *history_start;
static int history_not_initialized;
static list_t *previous_command;

/**
* get_history_start_address – Addresses of history start
* Return: history start Address
*/
list_t **get_history_start_address()
{
if (history_not_initialized == 1)
{
previous_command = NULL;
history_start = NULL;
history_not_initialized = 0;
}

return (&history_start);
}

/**
* get_previous_command_address - Addresses previous command
* Return: previous entered command
*/
list_t **get_previous_command_address()
{
if (history_not_initialized == 1)
{
previous_command = NULL;
history_start = NULL;
history_not_initialized = 0;
}

return (&previous_command);
}

/**
* print_history – gives commands given by the su
* Return: print 1 if the code passed
*/
get_alias_head(
{
list_t *current_node;
char *number_string;
int i, length;
int counter = *get_history_lines_count() % 4096;

for (current_node = *get_history_start_address(); current_node != NULL; current_node = current_node->next)
{
number_string = num_to_str(counter++);
length = _puts(number_string);

for (i = length; i < 7; i++) /* 5 per number, 2 additional */
_puts(" ");
_puts(current_node->str);
_puts("\n");
free(number_string);
}
return (1);
}

/**
* manage_history - Adds a command to the history
* @input: su input
*/
void manage_history(char *input)
{
if (previous_command == NULL || input[0] != ' ' || _strcmp(previous_command->str, input) != 0)
previous_command = add_node_end(get_history_start_address(), input);
}

/**
* clear_history - clears the history
*/
void clear_history(void)
{
free_list(*get_history_start_address());
}

