#include "shell.h"

/**
* error_message: Message to display as error
* error_handler - Handles an error
* This function takes an error message as input, prints it as an error, and then exits the program with the current errno value.
*/
void error_handler(char *error_message)
{
/* Print the error message */
perror(error_message);
/* Exit the program with the current errno value */
exit(errno);
}

/**
* argument: Argument passed to builtin
* builtin_error_display – shows error for functions
* error_msg: malfunctioning message
* This function takes an error message and an argument, constructs a formatted error message, and then writes it to STDERR. It also sets the process exit code to 2.
*/
void builtin_error_display(char *error_msg, char *argument)
{
int msg_length = _strlen(error_msg);
char *initial_av = get_first_av();

/* Write the initial argument value to STDERR */
write(STDERR_FILENO, initial_av, _strlen(initial_av));
/* Write the formatted error message to STDERR */
write(STDERR_FILENO, ": 1: ", 5);
write(STDERR_FILENO, error_msg, msg_length);
write(STDERR_FILENO, argument, _strlen(argument));
write(STDERR_FILENO, "\n", 1);
/* Set the process exit code to 2 */
set_process_exit_code(2);
}

