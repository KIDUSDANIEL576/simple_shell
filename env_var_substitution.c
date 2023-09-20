#include "shell.h"

/**
* replace_dollar_vars - Replaces doll vars '$'
* @cmd: Array of commands
*/
void replace_dollar_vars(char **cmd)
{
int index;
char *env_value;

if (cmd[0] == NULL)
return;

/* Go through command arguments and substitute the  necessary ones using var like  $? */
/* Go through command arguments and substitute the  necessary ones using var like $$*/
for (index = 1; cmd[index] != NULL; index++)
{
if (cmd[index][0] != '$')
continue;
/* The argument starts with '$' here */

if (_strcmp(&cmd[index][1], "?") == 0)
{
free(cmd[index]);
cmd[index] = num_to_str(*get_exit_code());
return;
}

if (_strcmp(&cmd[index][1], "$") == 0)
{
free(cmd[index]);
cmd[index] = num_to_str(getpid());
return;
}

env_value = _getenv(&cmd[index][1]);
if (env_value != NULL)
{
free(cmd[index]);

cmd[index] = copy_string(env_value);
}
}
}

