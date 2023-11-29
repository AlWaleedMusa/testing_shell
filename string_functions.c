#include "main.h"

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */

int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}

/**
 * _strcat - main function of the prototype
 *
 * @src: Concatenation parameter
 *
 * @dest: Concatenation parameter
 *
 * Return: dest
*/

char *_strcat(char *dest, char *src)
{
	int l, m;

	l = 0;
	m = 0;

	while (dest[l] != '\0')
	{
		l++;
	}

	while (src[m] != '\0')
	{
		dest[l] = src[m];
		l++;
		m++;
	}
	dest[l] = '\0';
	return (dest);
}
