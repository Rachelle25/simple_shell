#include "holberton.h"

/**
 * _environment - function that gets PATH from environment
 * @env: environment
 * @comd: command to add
 * Return: resv_concat
 */

char *_environment(char **env, char *comd)
{
int i, c, len = 0;
char **new_env = NULL;
char array_path[5];
char *path_char, *resv_concat;

for (i = 0; env[i] != NULL; i++)
{
for (c = 0; c < 4; c++)
array_path[c] = env[i][c];

array_path[c] = '\0';

if (_strcmp(array_path, "PATH") == 0)
{
for (c = c + 1; env[i][c] != '\0'; c++)
len++;
path_char = malloc(sizeof(char) * len + 1);
if (path_char == NULL)
return (NULL);

for (c = 5; env[i][c] != '\0'; c++)
path_char[c - 5] = env[i][c];
path_char[c - 5] = '\0';
break;
}
}

new_env = brokentoken(path_char, ":");
resv_concat = get_dir_concat(new_env, comd);
free(path_char);
return (resv_concat);
}

/**
 * _dir_concat - function adding command
 * @new_env: directory array
 * @comd: command to add
 * Return: new_env
 */

char *_dir_concat(char **new_env, char *comd)
{
char *dir_concat;
int i;

for (i = 0; new_env[i] != NULL; i++)
{
dir_concat = _strdup(new_env[i]);
dir_concat = _strcat(dir_concat, "/");
dir_concat = _strcat(dir_concat, comd);
if (access(dir_concat, X_OK) == 0)
{
free(new_env);
return (dir_concat);
}
free(dir_concat);
}
free(new_env);
return (0);
}
