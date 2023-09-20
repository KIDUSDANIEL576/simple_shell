#include "shell.h"

static char *INITIAL_ARG;

int argument_handler(int ac, char **av, int *exec_file);
void signalHandler(int sig_num);
char *get_initial_arg();

/**
* av: Array of arguments
* ac: number of arguments
* main – Entrance pt
* Return: 0 if it pass
*/

int main(int ac, char **av)
{
int read, exec_file = 0;
char *buff = NULL;
size_t buff_len = 0;
int fd;

INITIAL_ARG = av[0];

signal(SIGINT, signalHandler);
fd = argument_handler(ac, av, &exec_file);

while (1)
{
if (isatty(STDIN_FILENO) == 1 && exec_file == 0)
write(STDOUT_FILENO, "$ ", 2);

read = getline(&buff, &buff_len, stdin);
if (read == EOF)
{
free(buff);
exit(*process_exit_code());
}

buff = handle_comment(buff);
_strtok(buff, "\n");

handling_semicolon_and_operators(buff, read, av[0]);
}

free(buff);
if (exec_file)
close(fd);
return (*process_exit_code());
}

/**
* exec_file: exec commands from file
* ac: arguments number
* argument_handler - arguments passed to main
* av: strings array
* Return: fd to file
*/
int argument_handler(int ac, char **av, int *exec_file)
{
int fd = STDIN_FILENO;
char *err_msg = "Error: more than one argument\n";

if (ac > 2)
{
write(STDERR_FILENO, err_msg, _strlen(err_msg));
exit(1);
}
if (ac == 2)
{
fd = open(av[1], O_RDONLY);
*exec_file = 1;
}
if (fd == -1)
{
perror(av[0]);
exit(1);
}

return (fd);
}

/**
* sig_num: Sg no
* signalHandler - process to last
*/

void signalHandler(int __attribute__((unused))sig_num)
{
write(STDIN_FILENO, "\n$ ", 3);
}

/**
* get_initial_arg - passed to main
* Return: arg to main
*/
char *get_initial_arg(void)
{
return (INITIAL_ARG);
}

