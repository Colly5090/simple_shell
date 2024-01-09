#include "main.h"
/**
 * prompt - function to prompt user for input
 * Return: nothing
*/
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(1, "#cisfun$ ", 9);
}
