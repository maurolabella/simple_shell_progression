#include "main.h"

/**
 * insertNull - inserts null byte at given index
 * @str: input string
 * @index: index to insert null byte
 */
void insertNull(char *str, unsigned int index)
{
	str[index] = '\0';
}

/**
 * displayPrompt - displays shell prompt
 */
void displayPrompt(void)
{
	write(STDERR_FILENO, "$ ", 2);
}

/**
 * dispPrmpt_loop - displays shell prompt while in loop
 */
void dispPrmpt_loop(void)
{
	write(STDERR_FILENO, "> ", 2);
}



/**
 * displayNewLine - displays new line
 */
void displayNewLine(void)
{
	write(STDOUT_FILENO, "\n", 1);
}

/**
 * sigintHandler - catches SIGINT signal and reset signal
 * @sigint: signal from stdint
 */
void sigintHandler(int sigint)
{
	(void)sigint;
	signal(SIGINT, sigintHandler);
	displayNewLine();
	displayPrompt();
	fflush(stdout);
}
