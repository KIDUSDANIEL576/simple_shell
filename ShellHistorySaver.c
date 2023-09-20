#include "shell.h"

/**
* save_history - Saves the history to the home directory
*/

void save_history(void)
{
list_t *current_node;
int file_descriptor;
char *home_directory;

home_directory = _getenv("HOME");
if (home_directory == NULL)
home_directory = "/";

if (chdir(home_directory) == -1)
return;

file_descriptor = open(".simple_shell_Cmd_History_Handler", O_CREAT | O_RDWR | O_APPEND, 0666);
if (file_descriptor == -1)
return;

for (current_node = *get_history_addrss(); current_node != NULL; current_node = current_node->next)
{
write(file_descriptor, current_node->str, current_node->len);

write(file_descriptor, "\n", 1);
}

close(file_descriptor);
}

