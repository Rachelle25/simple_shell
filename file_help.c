#include "holberton.h"

/**
 * print_exit - function that calls the text file of exit
 * @vars: Structure to call
 * Return: 0
 */

char print_exit(input_v *vars)
{
char *str = NULL;

(void)vars;
str = read_file("exit");
write(1, str, _strlen(str));
return (0);
}

/**
 * print_pwd - function that calls the text file of pwd
 * @vars: Structure to call
 * Return: 0
 */

char print_pwd(input_v *vars)
{
char *str = NULL;

(void)vars;
str = read_file("pwd");
write(1, str, _strlen(str));
return (0);
}

/**
 * print_cd - function that calls the text file from cd
 * @vars: Structure to call
 * Return: 0
 */

char print_cd(input_v *vars)
{
char *str = NULL;

(void)vars;
str = read_file("cd");
write(1, str, _strlen(str));
return (0);
}

/**
 * print_help - function that calls the help text file of the help
 * @vars: Structure to call
 * Return: 0
 */

char print_help(input_v *vars)
{
char *str = NULL;

(void)vars;
str = read_file("help-help");
write(1, str, _strlen(str));
return (0);
}
