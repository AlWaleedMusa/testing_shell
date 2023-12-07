#include "main.h"

/**
 *
*/
int cd_func(char *commands_array[], char *argv)
{
	if (commands_array[1] == NULL)
	{
		fprintf(stderr, "%s: expected argument to \"cd\"\n", argv);
	}
	else
	{
		if (chdir(commands_array[1]) != 0)
		{
			perror("Error");
		}
	}
	return (0);
}


/**
 * 
*/
int exit_func(char *commands_array[], char *argv)
{
	(void)commands_array;
	(void)argv;

	exit(0);
}


/**
 * 
*/
int env_func(char *commands_array[], char *argv)
{
	int i = 0;

	(void)commands_array;
	(void)argv;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	exit(0);
}


/**
 * 
*/
FuncPtr find_builtin(char *name, struct FuncInfo *funcs, int num_funcs)
{
	int i = 0;
	char *token = strtok(name, " \n");
	
	if (token == NULL)
	{
		return (NULL);
	}

	while (i < num_funcs)
	{
		if (strcmp(token, funcs[i].name) == 0)
		{
			free(token);
			return (funcs[i].func);
		}
		i++;
	}
	return (NULL);
}


/**
 * 
*/
int builtin(char *commands_array[], char *argv)
{
	struct FuncInfo funcs[] = {
		{"exit", exit_func},
		{"env", env_func},
		{"cd", cd_func}};

	int num_funcs = sizeof(funcs) / sizeof(struct FuncInfo);
	FuncPtr func = find_builtin(commands_array[0], funcs, num_funcs);

	if (func != NULL)
	{
		func(commands_array, argv);
		return (0);
	}
	return (-1);
}
