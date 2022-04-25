#include "main.h"

/**
 * countArgs - count the number of arguments
 * @args: input array of strings
 * Return: number of strings
 */
int countArgs(char **args)
{
	register int i = 0;

	while (args[i])
		i++;
	return (i);
}

/**
 * _atoi - change string to an integer
 * @s: input string
 * Return: -1 if it's not a valid number, else the converted number
 */
int _atoi(char *s)
{
	register int i = 0;
	unsigned long num = 0;

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + s[i] - '0';
		else
			return (-1);
		i++;
	}
	if (num > INT_MAX)
	{
		return (-1);
	}
	return (num);
}

/**
 * depureBuffer - work the command string
 *
 * @buffer: the string received
 */
void depureBuffer(char *buffer)
{
	size_t i = 0, x = 0;
	char c;

	while ((c = buffer[i++]) != '\0')
	{
		if ((c == 92 && buffer[i] == 10) || (c == 32 && buffer[i] == 10))
		{
			i++;
			continue;
		}
		else if ((c == 32 && buffer[i] == 32) || c == 9 || c == 10)
		{
			continue;
		}
		else
		{
			buffer[x++] = c;
		}
	}
	buffer[x] = '\0';
}
