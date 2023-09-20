#include "shell.h"
#define BUFFER_LENGTH 32

/**
* @text: line of words
* @fd:  the file descriptor
* read_text – line of fd
* Return: 1 if the code pass
*/
int read_text(const int fd, char **text)
{
Int	ret;
char	*temp;
char	buf[BUFFER_LENGTH + 1];
static char *str[4864];

if (fd < 0 || BUFFER_LENGTH <= 0 || text == NULL || read(fd, buf, 0) < 0)
return (-1);
while ((ret = read(fd, buf, BUFFER_LENGTH)) > 0)
{
buf[ret] = '\0';
if (!str[fd])
str[fd] = _strdup(buf);
else
{
temp = f_strjoin(str[fd], buf);
free(str[fd]);
str[fd] = temp;
}
if (_strchr(str[fd], '\n'))
break;
}
if (str[fd] == NULL && ret == 0)
return (-1);
return (f_read_text(str, text, fd));
}

/**
* @text: line of words
* @str: hold files
* @fd: the file descriptor
* f_read_text – reads from the file descriptor
* Return: 1 if the code passes
*/
Int f_read_text(char **str, char **text, int fd)
{
char	*temp;
int	len;

len = 0;
while (str[fd][len] != '\0' && str[fd][len] != '\n')
len++;
*text = f_strsub(str[fd], 0, len);
if (str[fd][len] == '\n')
{
temp = _strdup(&str[fd][len + 1]);
free(str[fd]);
str[fd] = temp;
if (str[fd][0] == '\0')
f_strdel(&str[fd]);
}
else
f_strdel(&str[fd]);
return (1);
}

/**
* @cmds:  strings to execute
* _assist - simulate assist commands
* Return
* 0 if THE VALUE >1 	&	 -1 if it is an error
*/
int _assist(char **cmds)
{

int fd, i = 1, result = -1;
char *text = NULL;

while (cmds[i])
{
fd = open(cmds[i], O_RDONLY);
if (fd != -1)
{
result = 0;
while (read_text(fd, &text) == 1)
{
free(text);
puts(text);
}
close(fd);
}
i++;
}

return (result);
}

