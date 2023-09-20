#include "shell.h"

/**
* env - Display the environment variables
*/
void env(void)
{
int index;
char **env = __environ;

for (index = 0; env[index]; index++)
{
write(STDOUT_FILENO, env[index], _strlen(env[index]));
write(STDOUT_FILENO, "\n", 1);
}

set_process_exit_code(0);
}

/**
* name: Name of new variable
* value: Value of  new variable
* _setenv - Add or modify an environment variable
* Return: 1 if ok, -1 if it malfunctions
*/

int _setenv(char *name, char *value)
{
int env_index, new_var_length;

if (validate_env_name(name) == -1)
return (-1);

env_index = get_env_index(name);
if (env_index == -1)

{/* create a new variable if it doesn’t exist */
int env_count = 0;
int old_size, new_size;

while (__environ[env_count] != NULL)
env_count++;

old_size = sizeof(char *) * (env_count);
new_size = sizeof(char *) * (env_count + 2);
__environ = _realloc(__environ, old_size, new_size);
if (__environ == NULL)
dispatch_error("Error reallocating a memory for a new variable");

env_index = env_count;

__environ[env_count + 1] = NULL;
}
else
{
free(__environ[env_index]);
}

new_var_length = _strlen(name) + _strlen(value) + 2;

__environ[env_index] = allocate_memory(sizeof(char) * new_var_length);
_strcpy(__environ[env_index], name);
_strcat(__environ[env_index], "=");
_strcat(__environ[env_index], value);

set_process_exit_code(0);
return (1);
}

/**
* _unsetenv - Delete an env var
* name: environment variable name to delete
*
* Return: 1 if ok , -1 if it fails
*/
int _unsetenv(char *name)
{
int env_index, i;

env_index = get_env_index(name);
if (env_index >= 0)

{/* If variable exists, delete it */

free(__environ[env_index]);

for (i = env_index; __environ[i] != NULL; i++)
__environ[i] = __environ[i + 1];

set_process_exit_code(0);
return (1);
}

set_process_exit_code(0); /* points that no mal function occurred */

return (1);
}

/**
* _cd - Change directory
* path: Path to differ directory to
* Return: 1 if ok, -1 if it fails
*/
int _cd(char *path)
{
char buff[1024];
char *oldpwd;
char *_path = path;

if (_strcmp(path, "-") == 0)
path = _EnvVarFetcher("OLDPWD");

if (path == NULL)
{
print_builtin_error("cd: OLDPWD not set", "");
return (-1);
}
path = duplicate_string(path);

oldpwd = getcwd(buff, 1024);

if (oldpwd == NULL)
{
free(path);
print_builtin_error("cd: couldn't get current directory", "");
return (-1);
}

if (chdir(path) == -1)
{
free(path);
print_builtin_error("cd: can not change the directory to ", _path);
set_process_exit_code(1);
return (-1);
}

/* Update environment variables */
_setenv("OLDPWD", oldpwd);
_setenv("PWD", path);
free(path);
set_process_exit_code(0);
return (1);
}

/**
* _alias - Define an alias command
* commands: List of commands
*
* Return: -1 for error, 0 if it pass
*/

int _alias(int print_history(void);
)
{
int status = 0;
list_t *curr;
list_t *out_head = NULL;
list_t **alias_addrs = his;

if (commands[1] == NULL)

{ /* list of  all the aliases */

for (curr = *alias_addrs; curr != NULL; curr = curr->next)
{
_EchoShell(curr->str);
_EchoShell("\n");
}
set_process_exit_code(0);

return (1);
}

status = handle_alias_args(commands, &out_head);

for (curr = out_head; curr != NULL; curr = curr->next)
{
_EchoShell(curr->str);
_EchoShell("\n");
}

free_list(out_head);

return (status);
}

