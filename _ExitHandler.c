#include "shell.h"

/**
* input: User's input
* cmds: User input as ary cmd
* process_exit - exit command check
* parsed_cmds:  parsed commands ary
* Return 0 if the command does not correspond to ‘exit’, and -1 if the vice versa.
*/
int process_exit(char *input, char **parsed_cmds, char **cmds)
{
int exit_status;

/* for do not exit */
if (cmds[0] == NULL || _strcmp(cmds[0], "exit") != 0)
return (0);

/* for exit */
if (cmds[1] == NULL)
{
write_history();
free_allocs(input, parsed_cmds, cmds, F_BUFF | F_CMDS);
if (*process_exit_code() == 127)
exit(2);
exit(0);
}

exit_status = calculate_exit_status(cmds[1]);
/* Exit status */
if (exit_status >= 0)
{
write_history();
free_allocs(input, parsed_cmds, cmds, F_BUFF | F_CMDS);
exit(exit_status);
}

/* Exit status checked and it is illegal */
print_builtin_error("exit: Illegal number: ", cmds[1]);
return (-1);
}

/**
* input: User's input
* calculate_exit_status - Exit status number
* Return: leave as a num, -1 if it fails
*/
int calculate_exit_status(char *input)
{
int i;
int exit_status = 0;

for (i = 0; input[i] != '\0'; i++)
{
if (input[i] == '\n')
return (exit_status);

if (input[i] < '0' || input[i] > '9')
return (-1);

exit_status *= 10;
exit_status += input[i] - '0';
}

return (exit_status);
}

