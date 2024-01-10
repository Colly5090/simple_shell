#include "main.h"
/**
 * main - entry point to the simple shell
 * @argc: number of arguments from user
 * @argv: array of arguments
 * Return: 0 on success
*/
int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
	char *input, **args, *path = NULL;
	int is_builtin, x;
	size_t length;

	while (1)
	{
		(void) argc, (void) argv;
		prompt();
		input = read_input();
		if (input == NULL)
			continue;
		comment(input);

		length = _strlen(input);
		if (length > 0 && input[length - 1] == '\n')
			input[length - 1] = '\0';
		if (strchr(input, ';') != NULL)
			separator(input);
		else
		{
			args = token_input(input);
			if (args[0] != NULL)
			{
				is_builtin = is_built_ins(args[0]);
				if (is_builtin == 1)
				{
					exec_built_ins(args);
				}
				else if (is_builtin == 0)
				{
					path = getpath(args[0]);
					exec_external(args, path);
				}
				/*if (path !=  NULL)*/
					/*free(path);*/
				/*else*/
				/*{*/
				/*	perror("./shell: check wrong");*/
				/*}*/
				for (x = 0; args[x] != NULL; x++)
					free(args[x]);
				free(args);
				if (path != NULL)
					free(path);
			}
		}
		free(input);
	}
	/*free(input);*/
	return (0);
}
