#include "shell.h"

static int exit_status;
static int is_exit_status_initialized = 1;

/**
* get_exit_status - Returns the address of exit_status
*
* Return: Address of exit_status
*/
int *get_exit_status()
{
if (is_exit_status_initialized)
{
exit_status = 0;
is_exit_status_initialized = 0;
}

return (&exit_status);
}

/**
* update_exit_status - Updates the value of exit_status
* @status: The new exit status
*/
void update_exit_status(int status)
{
exit_status = status;
}

