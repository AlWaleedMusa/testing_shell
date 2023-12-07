#include "main.h"


/**
 * 
*/
int exit_func(void)
{
	exit(0);
}


/**
 * 
*/
int env_func(void)
{
	int i = 0;

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
int builtin(char *cmd)
{
	struct FuncInfo funcs[] = {
		{"exit", exit_func},
		{"env", env_func}};

	int num_funcs = sizeof(funcs) / sizeof(struct FuncInfo);
	FuncPtr func = find_builtin(cmd, funcs, num_funcs);

	if (func != NULL)
	{
		func();
		while (funcs != NULL)
		{
			free(funcs->name);
		}
		return (0);
	}
	return (-1);
}
