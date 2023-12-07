#include "main.h"

/**
 * 
*/
int handle_command(char *commands_array[], char *argv)
{
	if (commands_array[0] == NULL)
	{
		return (-1);
	}

	if (builtin(commands_array, argv) != 0)
	{
		execute_cmd(commands_array, argv);
	}
	return (0);
}
