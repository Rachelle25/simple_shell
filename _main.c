#include "holberton.h"

/**
 * _handle_ctrld - simple shell
 * @vars: argument count
 * @len: argument vectors
 */
void _handle_ctrld(input_v *vars, int len)
{
if (len == -1)
{
free(vars->buffer);
exit(0);
}
}

/**
 * _main - function that evaluates whether the command exists
 * @ac: count
 * @av: array
 * @env: enviroment
 * Return: message
 */

int _main(int ac, char **av, char **env)
{
input_v var = {0, NULL, NULL, NULL, 0};
size_t cant_buff = 0;
ssize_t len = 0;
char delimit[] = " \n\r\t";

(void)ac;
var.name_pro = av[0];
if (isatty(STDIN_FILENO))
write(1, "#cisfun$ ", 9);
while ((len = getline(&(var.buffer), &cant_buff, stdin)) != -1)
{
var.count++;
if (len > 1 && *var.buffer != '\n')
{
var.array_inputs = brokentoken(var.buffer, delimit);
if (var.array_inputs[0] != NULL)
{
var.exitstatus = check_for_comand(&var, env);
if (var.exitstatus == 0)
var.exitstatus =
comd_handling(&var, env);
}
else
free(var.array_inputs);
}
if (isatty(STDIN_FILENO))
write(1, "#cisfun$ ", 9);
}
if (isatty(STDIN_FILENO))
write(1, "\n", 1);
handle_ctrld(&var, len);
return (var.exitstatus);
}
