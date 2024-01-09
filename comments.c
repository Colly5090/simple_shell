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
	while (check != NULL)
	{
		if (check == input || *(check - 1) == ' ')
			check = '\0';
		check = strstr(check + 1, "#");
	}
	/*if (check != NULL)*/
	/*{*/
		/* *check = '\0';*/
	/*}*/
}
