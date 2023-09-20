#include "shell.h"

/**
* check_env_name - Checks the validity of an environment variable name
* name: String to be checked
* Return: 0 if ok, -1 if it fails
*/
int check_env_name(char *name)
{
if (name == NULL)
{
display_builtin_error("setenv: Requires 2 arguments", "");
return (-1);
}

if (!verify_env_var_name(name))
{
display_builtin_error("setenv: Name not valid ", name);
return (-1);
}

return (0);
}

/**
* verify_env_var_name - Verifies if the environment variable name is valid
* Name: String to be verified
* Return: 1 if valid, 0 if not valid
*/
int verify_env_var_name(char *name)
{
int i;
/* Check that name is a valid env_var name (without "=") */
for (i = 0; name[i] != '\0'; i++)
if (name[i] == '=')
return (0);

return (1);
}

/**
* Name: name hunt
* find_env_index – checks var & returns index
* Return: -1 if malfunction occurs
*/

int find_env_index(char *name)
{
int i;
int len = string_length(name);

for (i = 0; __environ[i] != NULL; i++)
if (string_compare(__environ[i], name, len) == 0)
return (i);

return (-1);
}

