#include "main.h"
/**
 * user_args - Fill an array with every input typed by the user
 * @entry: String with the input
 * @arguments: Array to be filled
 * Return: Length of the array
 */
int user_args(char *entry, char **arguments)
{
	int i = 0;
	char *token, *aux = entry;

	token = strtok(entry, " \t\n\r"); /** Extract the first token (command) */
	arguments[i] = token; /** Store the command in arguments array */

	while (aux != NULL)
	{
	i++;
	token = strtok(NULL, " \t\n\r"); /** Extract subsequent tokens (arguments) */
	aux = token;
	arguments[i] = token; /** Store the argument in arguments array */
	}
	arguments[i] = NULL; /** Mark the end of the array */
	return (i); /** Return the length of arguments[] */
}
