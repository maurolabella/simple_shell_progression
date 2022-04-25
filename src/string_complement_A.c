#include "main.h"

/**
 * splitString - splits string into an array of strings
 * separated by spaces
 * @cart: input cart
 * Return: TRUE if able to split, FALSE if not
 */
int splitString(config *cart)
{
	/**register unsigned int i = 0, l = 0;
	char *tok, *cpy;*/

	if ((/**l =*/countWords(cart->buffer)) == 0)
	{
		cart->args = NULL;
		free(cart->buffer);
		return (FALSE);
	}
	args_Generator(cart);

	/**cart->args = malloc((l + 1) * sizeof(char *));
	cpy = _strdup(cart->buffer);
	tok = _strtok(cpy, " ");
	while (tok)
	{
		cart->args[i] = _strdup(tok);
		tok = _strtok(NULL, " ");
		i++;
	}
	cart->args[i] = NULL;
	free(cpy);*/
	return (TRUE);
}

/**
 * args_Generator - new approach to args generation
 * @cart:
 * Return: int
 */
void args_Generator(config *cart)
{
	char argBuilder[BUFSIZE] = {'\0'};
	register int i = 0, k = 0, l = 0, inQuotes = -1;

	while (cart->buffer[i])
	{
		if (cart->buffer[i] == '\"')
		{
			inQuotes = (-1) * inQuotes;
			i++;
			continue;
		}
		if (inQuotes == 1 || (cart->buffer[i] != ' ' && cart->buffer[i] != '\t'))
		{
			argBuilder[k++] = cart->buffer[i++];
			continue;
		}
		else
		{
			if (i == 0 || cart->buffer[i - 1] == ' ' || cart->buffer[i - 1] == '\t')
			{
				i++;
				continue;
			}
			else
			{
				argBuilder[k] = '\0';
				cart->args = realloc(cart->args, ((l + 2) * sizeof(char *)));
				cart->args[l] = _strdup(argBuilder);
				argBuilder[k = 0] = '\0';
				i++, l++;
			}
		}
	}
	if (argBuilder[0] != '\0')
	{
		argBuilder[k] = '\0';
		cart->args = realloc(cart->args, ((l + 2) * sizeof(char *)));
		cart->args[l] = _strdup(argBuilder);
		cart->args[l + 1] = NULL;
	}
	else
		cart->args[l] = NULL;
}

/**
 * countWords - count number of words in a string
 * @str: input string
 * Return: number of words
 */
unsigned int countWords(char *str)
{
	register int words = 0;
	/* int wordOn = FALSE;*/

	while (*str)
	{
		if (*str != ' ' && (!*(str + 1) || (*(str + 1) == ' ')))
			words++;
		str++;
	}

	/*
	 *	{
	 *		if (isSpace(*str) && wordOn)
	 *			wordOn = FALSE;
	 *		else if (!isSpace(*str) && !wordOn)
	 *		{
	 *			wordOn = TRUE;
	 *			words++;
	 *		}
	 *		str++;
	 *	}
	 */
	return (words);
}

/**
 * isSpace - determines if char is a space
 * @c: input char
 * Return: TRUE or FALSE
 */
int isSpace(char c)
{
	return (c == ' ');
}

/**
 * string_append - concatenates two string with \
 * proper memory allocation
 * @s1: first pointer to receive the appended one.
 * @s2: second pointer to append
 * Return: char*
 */
char *string_append(char *s1, char *s2)
{
	size_t s1_length = 0, s2_length = 0, size = 0;

	s2_length = _strlen(s2);
	if (s1 == NULL)
	{
		s1 = calloc((s2_length + 1), sizeof(char));
	}
	else
	{
		s1_length = _strlen(s1);
		size = s1_length + s2_length + 1;
		s1 = realloc(s1, size);
	}
	s1 = _strcat(s1, s2);
	return (s1);
}
