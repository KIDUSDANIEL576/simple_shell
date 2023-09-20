#include "shell.h"

int builtin_env_vars(char **cmds);
int other_builtin_cmds(char **cmds);

/**
* execute_builtins - if the cmd is one it runs the function
* cmds: input parsed as an array
* Return: 1 if it’s a  builtin, 0 if the viceversa
*/

int execute_builtins(char **cmds)
{
if (cmds[0] == NULL)
return (0);

if (builtin_env_vars(cmds))
return (1);

if (other_builtin_cmds(cmds))
return (1);

return (0);
}

/**
* builtin_env_vars - Checks if a command is a builtin
* cmds: Array of commands
* Return: 1 if it is a builtin, 0 if the viceversa
*/

int builtin_env_vars(char **cmds)
{
if (_strcmp(cmds[0], "env") == 0)
{
if (cmds[1] != NULL)
return (0);

env();
return (1);
}

if (_strcmp(cmds[0], "setenv") == 0)
{
if (cmds[1] == NULL || cmds[2] == NULL || cmds[3] != NULL)
return (1);

_setenv(cmds[1], cmds[2]);
return (1);
}

if (_strcmp(cmds[0], "unsetenv") == 0)
{
if (cmds[1] == NULL || cmds[2] != NULL)
return (1);

_unsetenv(cmds[1]);
return (1);
}

return (0);
}

/**
* other_builtin_cmds - Checks if it is a  builtin
* cmds: commands arrays
* Return: 1 if it is a builtin, 0 if it is the viceversa
*/

int other_builtin_cmds(char **cmds)
{
if (_strcmp(cmds[0], "cd") == 0)
{
char *dir_path = cmds[1];

if (cmds[1] == NULL)
dir_path = _EnvVarFetcher("HOME");

if (dir_path == NULL)
dir_path = "/";

_cd(dir_path);
return (1);
}

if (_strcmp(cmds[0], "alias") == 0)
{
_alias(cmds);
return (1);
}

if (_strcmp(cmds[0], "help") == 0)
{
_help(cmds);
return (1);
}

if (_strcmp(cmds[0], "history") == 0)
{
if (cmds[1] != NULL)
{
print_builtin_error("history: No argument permitted ", "");
return (1);
}

/*_history();*/
/*return(1);*/
}
return (0);
}

