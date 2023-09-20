#ifndef __SHELL_H
#define __SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

/* mark the whole thing */

#define F_BUFF 1
#define F_CMD_L 2
#define F_CMDS 4

/* unlock the whole thing */

#include <fcntl.h>
#include <sys/stat.h>
#include <signal.h>
#include <dirent.h>


/**
* Description: node structure
* next: next node
* struct list_s - singly linked list
* len: length 
* str: string - string)
*/


typedef struct list_s
{
char *str;
unsigned int len;
struct list_s *next;
} list_t;


/*command excutor shell*/
int command_executor(char *buff, char **cmds_list, char *cmd, int __attribute__((unused))read, char *first_av);
void semicolon_and_operator_handler(char *buff, int read, char *first_av);
void or_operator_handler(char *buff_semicolon, int read, char *first_av);
int and_operator_handler(char *buff_semicolon, int read, char *first_av, int prev_flag);

/* _EnvDynMem.c */
void __attribute__((constructor)) create_dynamic_environ(void);
void __attribute__((destructor)) release_dynamic_environ(void);

char * getEnvVar(char *name);

/* evn_var_substitutor */
void  replace_dollar_vars(char **commands);
int *get_exit_code();
void set_process_exit_code(int code);

/* environment_history_shell */
void env(void);
int _setenv(char *name, char *value);
int _unsetenv(char *name);
int _cd(char *path);
int _alias(char **commands);
int _help(char **commands);
int print_history(void);

/*alias manager */
list_t ** get_head_of_alias();
list_t ** get_history_start_address();
list_t ** get_previous_command_address();
void manage_history(char *buff);
void clear_history(void);
void save_history(void);
void countLines(void);
int *getLineCount();

/* managing error */
void error_handler(char *error_message);
void builtin_error_display(char *error_msg, char *argument);
/* srt handler */
int string_length(const char *str);
char *string_copy(const char *src);
char *find_char(const char *str, int ch);
char *concatenate_strings(char *str1, const char *str2);
char *concatenate_n_chars(char *str1, const char *str2, size_t n);
char *integer_to_string(int number);
int	compare_n_chars(const char *str1, const char *str2, size_t n);

/* string slicer */
char *string_tokenizer(char *string, char *delimiter);
int _getline(char **buffer, size_t *buf_size, FILE *stream);
char *string_copy(char *copy, char *src);
char *copy_string_n(char *destination, char *source, int num);

/* env_inspector*/
int check_env_name(char *name);
int verify_env_var_name(char *name);
int find_env_index(char *name);
void add_or_update_alias(char *pair_alias);
int check_set_alias(char *pair_alias);
int evaluate_alias_input(char **commands, list_t **address_out);

/* file_line_reader */
int read_text(const int fd, char **text);
int f_read_text(char **str, char **text, int fd);

/*shell command processor*/
size_t display_list(const list_t *h);
list_t *append_node_end(list_t **head, const char *str);
void delete_list(list_t *head);

char *get_initial_arg(void);

/* input check */
int check_empty_input(char **cmds);

/* master memory */
void *memory_allocation(unsigned int size);
char *string_duplicate(char *string);
void free_double_pointer(char **double_pointer);
void free_allocated_memory(char *buffer, char **command_list, char **command_array, int flag);
void *_resize_memory(void *mem, unsigned int current_size, unsigned int new_size);

/* _CommandParser */
int check_PATH(char **cmds);
char *get_full_path(char *dir, char *file_name);
char **build_arg_array(char *input_str, char *delim);
int count_arguments(char *input_str, char *delim);

/* env_history_shell */
int execute_builtins(char **cmds);


/* comment filter */
char *remove_comment(char *input_str);


/*_EchoShell */

int output_string(char *str);


/* calculate exit status */
int process_exit(char *input, char **parsed_cmds, char **cmds);
int calculate_exit_status(char *input);

/* ShellStringOps */
char *str_concat(char const *s1, char const *s2);
char *str_sub(char const *s, unsigned int start, size_t len);
void mem_free(void **ap);
int     compare_strings(const char *str1, const char *str2);

/* shell.h
*/

#endif 

