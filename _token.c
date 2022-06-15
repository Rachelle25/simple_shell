#include "holberton.h"

/**
 *_token - item of the separating function
 *@buffer: string to separate
 *@delimiter: separator
 *Return: pointer to buffer
 */
char **_token(char *buffer, char *delimiter)
{
char **token = NULL;
size_t i = 0;
unsigned int mcount = 10;

if (buffer == NULL)
return (NULL);
token = malloc(sizeof(char *) * mcount);
if (token == NULL)
return (NULL);

while ((token[i] = _strtok(buffer, delimiter)) != NULL)
{
i++;
if (i == mcount)
{
token = _realloc(token, mcount, 2 * mcount);
if (token == NULL)
{
return (NULL);
}
}
buffer = NULL;
}
return (token);
}
