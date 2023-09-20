#include "shell.h"

/**
* check_empty_input – inspect command entry
* cmds: commands string
*
* Return: 1 if no code is entered , 0 if the viceversa
*/

int check_empty_input(char **cmds)
{
if (cmds[0] == NULL || _strcmp(cmds[0], "\n") == 0)
return (1);

return (0);
}
