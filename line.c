#include "holberton.h"

/**
 * line - function that gets the commands by input from the terminal
 * @buff: variable that stores
 * Return: len
 */
size_t line(char **buff)
{
ssize_t i = 0, ind_end = 0, n, len = 0;
char buffer[1000];

while (ind_end == 0 && (i = read(STDIN_FILENO, buffer, 1000 - 1)))
{
if (i == -1)
return (-1);

buffer[i] = '\0';
n = 0;
while (buffer[n] != '\0')
{
if (buffer[n] == '\n')
ind_end = 1;
n++;
}
if (len == 0)
{
len = i;
buff[0] = malloc(len + 1);
buff[0] = _strcpy(buff[0], buffer);
}
else
{
len += i;
buff[0] = _strcat(buff[0], buffer);
}
}

return (len);
}
