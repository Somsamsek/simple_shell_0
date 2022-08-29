
#ifndef SHELL_H
#define SHELL_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdarg.h>
#include <fcntl.h>
extern char **environ;

/**
 * struct type - struct of type of data
 * @type: type od data
 * @functiontype: pointer to de function
 */
typedef struct type
{
	char *type;
	int (*functiontype)(char *buffer, char **buff);
} data;

int get_env1(void);
void check(int s, char **buff, char *buffer, int check);
void writes3(char **buff, int cont);
void writes0(char **buff);
void writeexe(char **buff, int cont);
int extstatus(int *p);
void ret(void);
void prompt(void);
void sigintHandler(int sig_num);
char *_strtok(char *str, const char *delim);
char **getargs(char *buffer);
int count(char *buff, char *l);
void freeAll(char **buff);
int coincidence(char **buff, char *buffer);
int ext(char *buffer, char **buff);
ssize_t getline1(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);
void spaces(char *buffer);
int env(char *buffer, char **buff);
char *compare_path(char *buffer, char *path);
char *str_concat(char *s1, char *s2);
char *get_env(char *);
char *cpstring(char *path);
ssize_t getline1(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);
void *_calloc(unsigned int nmemb, unsigned int size);
int cd_fun(char *buff, char **buffer);
char *get_pwd(void);
void changepwd(char *pwd);
char *oldpwd(void);
unsigned int _strlen(char *str);
ssize_t _puts(char *str);
void _puts2(char *str);
char *unatoi(unsigned int count);
int help(char *cmd, char **abc);
void help_cd(char *cmd);
void help_exit(char *cmd);
void help_env(char *cmd);
void help_help(char *cmd);

#endif
