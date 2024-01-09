#include "main.h"
/**
 * is_built_ins - function to check for built-in commands
 * @command: built-in command from user
 * Return: -1 failed 1 built-in 0 not built-in
*/
int is_built_ins(const char *command)
{
if (command == NULL)
{
return (-1);
}
else if (_strcmp(command, "cd") == 0 ||
_strcmp(command, "pwd") == 0 ||
_strcmp(command, "exit") == 0 ||
_strcmp(command, "echo") == 0)
{
return (1);
}
else
{
return (0);
}
}
