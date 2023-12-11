#include "main.h"

/**
 * _strdup - entry point
 * @str: function parameter
 *
 * Return: 0
 */
char *_strdup(char *str)
{
	char *d;
	int q, w = 0;

	if (str == NULL)
		return (NULL);
	q = 0;
	while (str[q] != '\0')
		q++;

	d = malloc(sizeof(char) * (q + 1));

	if (d == NULL)
		return (NULL);

	for (w = 0; str[w]; w++)
		d[w] = str[w];

	return (d);
}
