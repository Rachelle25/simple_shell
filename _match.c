#include "holberton.h"

/**
 * _check_for_comand - function that compares the command entered.
 * @vars: pointer that directs to the command array.
 * @env: enviroment
 * Return: command function
 */
int _check_for_comand(input_v *vars, char **env)
{
unsigned int i;
comand_v check[] = {
{"exit", exit_func},
{"env", take_env},
{"help", help_func},
{NULL, NULL}
};
(void)env;

for (i = 0; check[i].p != NULL; i++)
{
if (_strcmp(vars->array_inputs[0], check[i].name) == 0)
{
break;
}
}
if (check[i].p != NULL)
{
return (check[i].p(vars, env));
}
return (0);
}

/**
 * _exit_func - function that handles the exit arguments
 * @vars: pointer that directs to the command array.
 * @env: enviroment
 * Return: output, status or error
 */

int _exit_func(input_v *vars, char **env)
{
int status = 0;
int len;
char *cont;
(void)env;

if (vars->array_inputs[1] != NULL)
{
status = _atoi(vars->array_inputs[1]);
if (status == -1)
{
cont = convers_integer(vars->count);
status = 2;
write(1, cont, _strlen(cont));
write(1, ": exit : Illegal number: ", 25);
len = _strlen(vars->array_inputs[1]);
write(1, vars->array_inputs[1], len);
write(1, "\n", 1);
free(cont);
free(vars->array_inputs);
return (2);
}
}
else if (vars->exitstatus != 0)
status = vars->exitstatus;
free(vars->array_inputs);
free(vars->buffer);
exit(status);
}

/**
 * _comd_handling - evaluate and execute commands
 * @vars: pointer that directs to the command array
 * @env: enviroment
 * Return: src_comd
 */

int _comd_handling(input_v *vars, char **env)
{
int child_pid, status = 0, in = 0;
char *src_comd, *cont;

if (access(vars->array_inputs[0], X_OK) == 0)
src_comd = vars->array_inputs[0];
else
{
src_comd = get_enviroment(env, vars->array_inputs[0]);
in = 1;
if (src_comd == NULL)
{
write(STDOUT_FILENO, vars->name_pro, _strlen(vars->name_pro));
write(STDOUT_FILENO, ": ", 2);
cont = convers_integer(vars->count);
write(STDOUT_FILENO, cont, _strlen(cont));
write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, vars->array_inputs[0],
_strlen(vars->array_inputs[0]));
write(STDOUT_FILENO, ": not found\n", 12);
free(cont);
free(src_comd);
free(vars->array_inputs);
return (127);
}
}
child_pid = fork();
if (child_pid == -1)
exit(1);
if (child_pid == 0)
{
execve(src_comd, vars->array_inputs, env);
exit(1);
}
wait(&status);
free(vars->array_inputs);
if (in == 1)
free(src_comd);
return (0);
}

/**
 * _take_env - function that gets global environment
 * @vars: pointer that directs to the command array
 * @env: enviroment
 * Return: env
 */

int _take_env(input_v *vars, char **env)
{
int n = 0;

(void)vars;
while (env[n] != NULL)
{
write(STDOUT_FILENO, env[n], _strlen(env[n]));
write(STDOUT_FILENO, "\n", 1);
n++;
}
free(vars->array_inputs);
return (1);
}
