#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <sys/stat.h>

/*struct stat buffer;*/
extern char **environ;
char *_strcpy(char *dest, char *src);
unsigned int _strspn(char *string, const char *subset);
char *_strchr(char *string, char c);
char **token_input(char *input);
char *_strtok(char *str, const char *sep);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *read_input(void);
void env_var(void);
void separator(const char *input);
void comment(char *input);
void exec_external(char **args, char *path);
void exec_built_ins(char **tokens);
int my_setenv(const char *name, const char *value);
int my_unsetenv(const char *name);
void prompt(void);
void exec_built_ins(char **tokens);
char *getpath(char *inputs);
int is_built_ins(const char *inputs);
void exec_input(char **argv);
char *_strcat(char *dest, const char *sour);
int _strcmp(const char *s1, const char *s2);
void execute(char **str, char **envp);
/*char **_strtok(char *str);*/
int pathchecker(char *cstr);
char *filechecker(char *strg);
int myownexit(char **args);
int inbuilt(char *str);
int _strlen(char *str);
/*int exec_external(char **args, char *path);*/
void exec_non_interactive(char **args, char *path);

#endif
