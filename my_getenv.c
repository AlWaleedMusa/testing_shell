#include "main.h"

/**
 *
*/
char *my_getenv(char *name)
{
	char *equal;
	int length;
	char **environment_variable = environ;

	while (*environment_variable != NULL)
	{
		equal = strchr(*environment_variable, '=');
		if (equal == NULL)
		{
			continue;
		}
		length = equal - *environment_variable;
		if (strncmp(*environment_variable, name, length) == 0 && name[length] == '\0')
		{
			return (equal + 1);
		}
		environment_variable++;
	}
	return (NULL);
}
