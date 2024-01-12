#include "main.h"
/**
 * comment - function to handle comments #
 * @input: input from user containing #
 * Return: nothing
*/
void comment(char *input)
{
	char *check;

	check = strchr(input, '#');
	if (check != NULL)
	{
		*check = '\0';
	}
}
