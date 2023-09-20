#include "shell.h"

/**
* delim: string pointing delimiters
* input_str: Command input given by the user
* build_arg_array - Constructs an arguments
* Return: strings array
*/
char **build_arg_array(char *input_str, char *delim)
{
int i, arg_count = 0;
char **arg_arr;
char *tok, *tok_ptr;
char *str_dup;

if (input_str == NULL)
dispatch_error("malfunction parsing the cmd\n");

/* Count arguments */
arg_count = count_arguments(input_str, delim);
/* memory allocation */
arg_arr = allocate_memory(sizeof(char *) * (arg_count + 1));
/* Storage for strings */
str_dup = duplicate_string(input_str);
tok_ptr = str_dup;
for (i = 0; i < arg_count; i++)
{
tok = _string_slicer(tok_ptr, delim);
if (tok == NULL)
break;
tok_ptr = NULL;
/* store command as single string */
arg_arr[i] = duplicate_string(tok);
}

arg_arr[i] = NULL;

free(str_dup);

return (arg_arr);
}

/**
* delim: split the args
* input_str: string cmd
* count_arguments - number of ARG
* Return: arguments in input_str
*/
int count_arguments(char *input_str, char *delim)
{
char *tok, *tok_ptr;
int count = 0;
char *str_dup = duplicate_string(input_str);

tok_ptr = str_dup;
while ((tok = _string_slicer(tok_ptr, delim)) != NULL)
{
count++;
tok_ptr = NULL;
}

free(str_dup);

return (count);
}

/**
* cmds: Array of strings containing the command and args
* check_path – path of  directoies
* Return: flag 0 if it is ok; -1 if it fails
*/
int check_PATH(char **cmds)
{
char *path_dirs, *path;
char *tok, *tok_ptr;
char *str_dup;
int flag = 127;

if (
cmds == NULL || cmds[0] == NULL ||
cmds[0][0] == '\0' || cmds[0][0] == '/'
)
return (127);

if (access(cmds[0], F_OK) == 0)
return (0);

path_dirs = __EnvVarFetcher("PATH");
if (path_dirs == NULL)
return (127);

str_dup = duplicate_string(path_dirs);
tok_ptr = str_dup;
while (1)
{
tok = _string_slicer(tok_ptr, ":");
if (tok == NULL)
break;
tok_ptr = NULL;

path = get_full_path(tok, cmds[0]);
if (access(path, F_OK) != -1)
{
free(cmds[0]);
cmds[0] = path;
flag = 0;
break;
}
free(path);
}
free(str_dup);
return (flag);
}

/**
* file_name: file name hunt
* dir: directory  representing path
* get_full_path - path to the file
* Return: String as a full path to "file_name"
*/
char *get_full_path(char *dir, char *file_name)
{
int dir_len = _strlen(dir);
int file_name_len = _strlen(file_name);
char *path;

path = allocate_memory(sizeof(char *) * (dir_len + file_name_len + 2));

_StringDuplicator(path, dir);
_strcat(path, "/");
_strncat(path, file_name, file_name_len + 1);

return (path);
}

