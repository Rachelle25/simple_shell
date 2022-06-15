#include "holberton.h"

/**
 * _strlen - calculate the lenght of a string
 * @s: input string
 * Return: will return 1 for each element of the array
 * array that is different from null
 */
int _strlen(char *s)
{
int iterador = 0;

while (s[iterador] != '\0')
{
iterador++;
}
return (iterador);
}

/**
 *_atoi - function that converts strings to integers
 *@s: input string
 *Return: integer
 */
int _atoi(char *s)
{
int sign = 1;

unsigned int num = 0;

do {
if (*s == '-')
sign = -1;
else if (*s >= '0' && *s <= '9')
num = (num * 10) + (*s - '0');
else if (*s < '0' || *s > '9')
return (-1);
else if (num > 0)
break;
} while (*(++s));

return (num * sign);
}
/**
 *convers_integer - function that converts integers to strings
 *@c: integer
 *Return: pointer to char
 */
char *convers_integer(int c)
{
char *num;
int tmp, digits;

tmp = c;

for (digits = 0; tmp != 0; digits++)
tmp /= 10;

num = malloc(sizeof(char) * (digits + 1));
if (num == NULL)
return (NULL);

num[digits--] = '\0';

for (; c; digits--)
{
num[digits] = (c % 10) + '0';
c /= 10;
}
return (num);
}

/**
 * _strcpy - copies the string pointed to by src
 * to the buffer pointed to by dest
 * @dest: string to copy to
 * @s: string to copy
 * Return: the pointer to dest
 *
 */

char *_strcpy(char *dest, char *s)
{
int ultimo = 0;

while (s[ultimo] != '\0')
{
dest[ultimo] = s[ultimo];
ultimo++;
}
dest[ultimo] = '\0';
return (dest);
}
