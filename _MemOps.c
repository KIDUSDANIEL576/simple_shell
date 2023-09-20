#include "shell.h"

/**
* size: alocsize
* malocc - memory allocation
*
* Return: Pointer to the newly allocated memory
*/
void *memory_allocation(unsigned int size)
{
char *new_memory = malloc(size);

if (new_memory == NULL)
dispatch_error("Error while allocating memory\n");

return (new_memory);
}

/**
* string: duplication
* str_dup - multiply string
* Return: new duplicate
*/
char *string_duplicate(char *string)
{
char *copy_string = _strdup(string);

if (copy_string == NULL)
dispatch_error("Error while making copy of string");

return (copy_string);
}

/**
* double_pointer: ~~``~~
* free_double_pointer - double pointer memory
*/

void free_double_pointer(char **double_pointer)
{
int i;

if (double_pointer == NULL)
return;

for (i = 0; double_pointer[i]; i++)
free(double_pointer[i]);

free(double_pointer);
}

/**
* free_allocated_memory – let go alloc
* command_array: arrays
* flag: pointing numbers
*/
void free_allocated_memory(char *buffer, char **command_list, char **command_array, int flag)
{
if (flag & F_BUFF)
free(buffer);
if (flag & F_CMD_L)
free_double_pointer(command_list);
if (flag & F_CMDS)
free_double_pointer(command_array);

free_list(*(get_alias_head()));
free_history();
}

