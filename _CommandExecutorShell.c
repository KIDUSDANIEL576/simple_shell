#include "shell.h"

void alias_handler(char **commands);
void cmd_not_found_handler(char *buff, char **cmds_list, char **commands, char *first_av);

/**
* buff: initial buffer read by functions
* Return: 0 on success
*/
void semicolon_and_operator_handler(char *buff, int read, char *first_av)
{
char **cmds_list = NULL;

command_executor(buff, cmds_list, buff, read, first_av);
}

/**
* read: read value
* Return: 0 if ok
*/
void or_operator_handler(char *buff_semicolon, int read, char *first_av)
{
int i, flag, prev_flag = -1;
char **cmds_list_2 = user_input_parser(buff_semicolon, "||");

for (i = 0; cmds_list_2[i] != NULL; i++)
{
flag = and_operator_handler(cmds_list_2[i], read, first_av, prev_flag);
prev_flag = flag;
}
free_double_pointer(cmds_list_2);
}

/**
* buff: functions
* Return: 0 if ok
*/
int and_operator_handler(char *buff_or, int read, char *first_av, int prev_flag)
{
int j = 0, flag = 1;
char **cmds_list_3 = user_input_parser(buff_or, "&&");

if (prev_flag == 0)
{
j++;
if (cmds_list_3[j] == NULL)
return (-1);
}

for (; cmds_list_3[j] != NULL; j++)
{
flag = command_executor(buff_or, cmds_list_3,
cmds_list_3[j], read, first_av);
prev_flag = flag;
}
free_double_pointer(cmds_list_3);
return (flag);
}

/**
* read: return read
* Return: 0 if it pass
*/

int command_executor(char *buff, char **cmds_list, char *cmd, int __attribute__((unused))read, char *first_av)
{
char **commands;
int child_pid, _err = 0, flag = 0, *status = process_exit_code();

commands = user_input_parser(cmd, " ");
var_replacement_handler(commands);
alias_handler(commands);

if (exit_handler(buff, cmds_list, commands) == -1 ||
enter_handler(commands) == 1	||
builtins_handler(commands) == 1)
{
free_double_pointer(commands);
return (-1);
}

child_pid = fork();
if (child_pid == -1)
{
free_allocations(buff, cmds_list, commands, F_BUFF | F_CMD_L | F_CMDS);
error_dispatcher(first_av);
}
else if (child_pid == 0)
{
_err = PATH_handler(commands);
execve(commands[0], commands, __environ);
if (_err != 0)
cmd_not_found_handler(buff, cmds_list, commands, first_av);
free_allocations(buff, cmds_list, commands, F_BUFF | F_CMD_L | F_CMDS);
error_dispatcher(first_av);
}
wait(status);
*status = WEXITSTATUS(*status);
if (*status == 2)
set_process_exit_code(127);
free_double_pointer(commands);
return (flag);
}

/**
* cmd list: cmd
* first av: passed executable
* cmd: string cmd
*/
void cmd_not_found_handler(char *buff, char **cmds_list, char **commands, char *first_av)
{
set_process_exit_code(127);
write(2, first_av, _strlen(first_av));
write(2, ": 1:", 5);
write(2, commands[0], _strlen(commands[0]));
write(2, ": not found\n", 12);
free_allocations(buff, cmds_list, commands, F_BUFF | F_CMD_L | F_CMDS);
exit(127);
}

