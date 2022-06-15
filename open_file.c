#include "holberton.h"

/**
 * read_file - Function that reads text files
 * @namefile: filename
 * Return: size in bits of stored read file
 */

char *read_file(char *namefile)
{
char *buffer = NULL;
int fd;
ssize_t size;
struct stat st;

fd = open(namefile, O_RDONLY);
if (fd == -1)
{
return (NULL);
}
fstat(fd, &st);
buffer = malloc(sizeof(char) * st.st_size + 1);
if (buffer == NULL)
{
return (NULL);
}
size = read(fd, buffer, st.st_size);
if (size < 0)
{
return (NULL);
}
close(fd);
buffer[size] = '\0';
return (buffer);
}

/**
 * help_func - Function that executes the help file
 * @vars: Structure to call
 * @env: Enviroment
 * Return: help_match
 */

int help_func(input_v *vars, char **env)
{
char *str = NULL;
char (*f)(input_v *h);

(void)env;
if (vars->array_inputs[1]) /* si hay segundo argumento */
{
f = help_match(vars);
f(vars);
}
else 
{
str = read_file("help");
write(1, str, _strlen(str));
free(str);
}
return (0);
}

/**
 * help_match - function that matches the commands after the help
 * @vars: Structure to call
 * @vars: Structure to call
 * Return: Pointed file
 */
char (*help_match(input_v *vars))(input_v *vars)
{
unsigned int i;
help_v h[] = {
{"exit", print_exit}, 
{"pwd", print_pwd},
{"cd", print_cd},
{"help", print_help},
{NULL, NULL}
};
for (i = 0; h[i].p != NULL; i++)
{
if (_strcmp(vars->array_inputs[1], h[i].name) == 0)
{
break;
}
}
return (h[i].p);
}
