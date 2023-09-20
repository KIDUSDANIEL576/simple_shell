#include "shell.h"

/**
* create environ - Creates an environ
*/

void create_dynamic_environ(void)
{
int env_count = 0;
char **dynamic_environ;

while (__environ[env_count] != NULL)
env_count++;

dynamic_environ = allocate_memory(sizeof(char *) * (env_count + 1));
for (env_count = 0;  __environ[env_count] != NULL; env_count++)
dynamic_environ[env_count] = duplicate_string(__environ[env_count]);

dynamic_environ[env_count] = NULL;


__environ = dynamic_environ;
}

/**
* release environ – release an environ
*/
void release_dynamic_environ(void)
{
free_dbl_ptr(__environ);
}

