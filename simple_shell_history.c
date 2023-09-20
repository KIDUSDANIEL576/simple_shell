#include "shell.h"

static int lineCount;

/**
* countLines – line counting
*/

void countLines(void)
{
char directory[512];

char buffer[1024];

int index, fileDescriptor, bytesRead;

char *homeDirectory;

lineCount = 0;

if (getcwd(directory, 512) == NULL)

return;

homeDirectory = _getenv("HOME");

if (homeDirectory == NULL)

homeDirectory = "";

if (chdir(homeDirectory) == -1)
return;

fileDescriptor = open(".simple_shell_history", O_RDONLY);

if (fileDescriptor == -1)

return;

while ((bytesRead = read(fileDescriptor, buffer, 1024)) != -1)
{

if (bytesRead == 0)

break;

for (index = 0; index < bytesRead; index++)

if (buffer[index] == '\n')

lineCount++;

}

chdir(directory);

}

/**
* getLineCount – returns line count
*
* Return: redirects line count
*/

int *getLineCount()

{

return (&lineCount);

}

