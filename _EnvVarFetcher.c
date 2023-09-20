#include "shell.h"

/**
* varName: Name of the environment variable
* getEnvVar - Returns a pointer to an environment variable value
* Return: Pointer to the value of the environment variable
*/
char *getEnvVar(char *varName)
{
int index;

for (index = 0; __environ[index] != NULL; index++)
if (_strncmp(__environ[index], varName, _strlen(varName)) == 0)
return (&__environ[index][_strlen(varName) + 1]);

return (NULL);
}

