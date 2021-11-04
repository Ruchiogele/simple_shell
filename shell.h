#ifndef _SHELL_H_
#define _SHELL_H_

extern char **environ;

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define DISPLAY(c) (write(STDOUT_FILENO, c, _strlen(c)))

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/** For Memory */

char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void free_env(char **env);
void *array_bytes(void *x, int d, unsigned int len);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

/** Handle Command-line Arguments */

int bui_hnd(char **cmd, int er);
void cmd_reader(char *filename, char **argv);
int Pa_th(char **cmd);
char *get_env_name(char *name);
char **cmd_sort(char *input);
int cmd_exe(char **tokens, char *line, int count, char **argv);
void fil_exec(char *line, int counter, FILE *fd, char **argv);
char *cmd_retrv(char *token, char *value);
int bui_chk(char **cmd);
void env_var_arr(char **envi);
void shell_exit(char **cmd, char *line, FILE *fd);

/** Functions For Strings */

char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
int _strlen(char *s);
int _putchar(char c);
char *str_tok(char *str, const char *tok);
unsigned int de_lim(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _atoi(char *s);
void array_rev(char *arr, int len);
int intlen(int num);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/**
 * struct built_in - declaring builtin struct
 * @command: pointer to char
 * @fun: function
 */

typedef struct  built_in
{
    char *command;
    int (*fun)(char **line, int er);
} bui_lt;

/** Handle Input */

void sgn_hnd(int sgn);
char *read_input(void);
void prompt(void);

/** Handle builtin functions */

int ch_dir(char **cmd, int er);
int help_dis(char **cmd, int er);
void rem_else_hash(char *buff);
int echo_bul(char **cmd, int er);
int history(char *input);
int his_display(char **cmd, int er);
int dis_env(char **cmd, int er);
void bui_ex(char **cmd, char *input, char **argv, int c);
int pr_echo(char **cmd);

/** Handle and Print Errors */

void pr_num(unsigned int n);
void pr_num_in(int n);
void dis_err(char *line, int c, char **argv);
void err_pr(char **argv, int c, char **cmd);
void print_error(char *input, int counter, char **argv);

#endif
