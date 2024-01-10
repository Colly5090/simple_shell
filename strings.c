#include "main.h"
/**
 * _strcmp - function to compare s1 to s2
 * @s1: first string
 * @s2: second string
 * Return: nothing
*/
int _strcmp(const char *s1, const char *s2);
int _strcmp(const char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0')
	{
	if (s1[x] != s2[x])
		{
		return (s1[x] - s2[x]);
		}
	x++;
	}
	return (0);
}

/**
  * _strlen - to check the length of strings
  * @str: string to check its length
  * Return: numb of the string
  */
int _strlen(char *str)
{
	int x = 0;

	if (str == NULL)
		return (0);
	while (*str++)
		x++;
	return (x);
}

/**
 * _strcat - to concantenates two strings
 * @dest: destination string
 * @sour: source string
 * Return: pointer to the new string
*/
char *_strcat(char *dest, const char *sour)
{
	char *result = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*sour != '\0')
	{
		*dest = *sour;
		dest++;
		sour++;
	}
	*dest = '\0';
	return (result);
}

/**
 * _strcpy - A function to that copies strings into one another
 * @dest: the first string as destination to copy to
 * @src: the second string as the source to copy from
 * Return: 0 success
 */
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}

/**
 * _strspn - A function that checks and print the length of substring
 * @string: the main string to scan for the subset
 * @subset: the subset strings to print its length
 * Return: number of character scan
 */
unsigned int _strspn(char *string, const char *subset)
{
	unsigned int x = 0;
	int i;

	while (*string)
	{
		for (i = 0; subset[i]; i++)
		{
			if (*string == subset[i])
			{
				x++;
				break;
			}
			else if (subset[i + 1] == '\0')
			{
				return (x);
			}
		}
		string++;
	}
	return (x);
}

/**
 * _strchr - A function to locate a character in a string
 * @string: the string to locate a character from
 * @c: the character to be located
 * Return: Null if failed or c on success
 */
/*char *_strchr(char *string, char c)*/
/*{*/
	/*int x;*/

	/*for (x = 0; string[x] >= '\0'; x++)*/
	/*{*/
		/*if (string[x] == c)*/
		/*{*/
			/*return (&string[x]);*/
		/*}*/
	/*}*/
	/*return (0);*/
/*}*/

