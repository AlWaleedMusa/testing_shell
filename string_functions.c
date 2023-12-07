#include "main.h"


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
 * _strcmp - The main function
 *
 * @s1: Function value
 *
 * @s2: Function value
 *
 * Return: s1, s2
*/

int _strcmp(char *s1, char *s2)
{
	int l = 0;

	while (s1[l] != '\0' && s2[l] != '\0')
	{
		if (s1[l] != s2[l])
		{
			return (s1[l] - s2[l]);
		}
			l++;
	}
		return (0);
}

/**
  * _memcpy - Entrey point
  *
  * @src: parameter deal with the function
  *
  * @dest: parameter deal with the function
  *
  * @n: parameter deal with the function
  *
  * Return: Copied memory
  */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int lol;

	for (lol = 0; lol < n; lol++)
	{
	dest[lol] = src[lol];
	}
	return (dest);
}

/**
  * _strchr - Entrey point
  *
  * @s: parameter deal with the function
  *
  * @c: parameter deal with function
  *
  * Return: Always 0
  */

char *_strchr(char *s, char c)
{
	int lmao;

	for (lmao = 0; s[lmao] >= '\0'; lmao++)
	{
	if (s[lmao] == c)
	return (s + lmao);
	}
	return (0);
}

/**
 * _strdup - entry point
 *
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

/**
 * _strncmp - Compare two strings
 * @str1: First string
 * @str2: Second string
 * @n: Number of characters to compare
 *
 * Return: 0 if first n characters of both strings match
 * or difference between first non-matching characters if they don't match.
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	for (; n > 0 && *str1 && (*str1 == *str2); --n, ++str1, ++str2)
	{
	}

	if (n == 0 || (*str1 == '\0' && *str2 == '\0'))
	{
		return (0); 
	}
	else
	{
		return (*(unsigned char *)str1 - *(unsigned char *)str2);
	}
}