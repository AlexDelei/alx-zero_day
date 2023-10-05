#include "main.h"
/**
 * not_found - Prints error message when a command is not found
 * @arguments: array of args typed by the user
 * @counter: Times that the shell has been executed
 * Return: Exit status
 */
int not_found(char **arguments, int counter)
{
	const char *shell_name = isatty(STDIN_FILENO) ? "hsh" : "./hsh";

	fprintf(stderr, "%s: %d: %s: not found\n", shell_name, counter, arguments[0]);
	return (127);
}
