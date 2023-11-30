#include "main.h"


/**
 * 
*/
void tokenize(char *str)
{
	char *word;
	char *breaker = " \n\t";
	char **str_array;
	int i = 0;

	str_array = malloc(sizeof(char) * 256);
	if (!str_array)
	{
		printf("Error allocating memory");
	}

	word = strtok(str, breaker);

	while (word != NULL)
	{
		str_array[i] = malloc(sizeof(char) * (_strlen(word) + 1));
		if (!str_array[i])
		{
			printf("Error allocating memory");
		}
		_strcpy(str_array[i], word);
		word = strtok(NULL, breaker);
		i++;
	}
	str_array[i] = '\0';
	handle_command(str_array);

	for (i = 0; str_array[i] != NULL; i++)
	{
		free(str_array[i]);
	}
	free(str_array);
}



/**
 * 
*/
bool check_spaces(char *arr[])
{
	while (arr)
	{
		if (*(*arr) != ' ')
		{
			return (false);
		}
		arr++;
	}
	return (true);
}



/**
 * 
*/
void handle_command(char *argv[])
{
	pid_t fork_id;
	char *cmd;
	int ex_checker;

	fork_id = fork();
	if (fork_id == 0)
	{
		cmd = argv[0];
		ex_checker = execve(cmd, argv, NULL);

		if (ex_checker == -1 && !check_spaces(argv))
		{
			printf("%s: command not found\n", cmd);
			exit(127);
		}
	}
	else
	{
		wait(NULL);
	}
}



/**
 * 
*/
int main(void)
{
	char *BUFFER = NULL;
	size_t BUF_size = 0;
	ssize_t input_count;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
		}
		input_count = getline(&BUFFER, &BUF_size, stdin);
		if (input_count == -1)
		{
			free(BUFFER);
			return(0);
		}
		else
		{
			tokenize(BUFFER);
		}
	}
	return (0);
}
