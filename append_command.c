#include "main.h"
/**
 * add_command - Concatenates an input with paths in global variable PATH
 * @dir_path: directory string to be appended with the command
 * @command: command to be concatenated with the directory
 * Return: Buffer to concatenated path
 */
char *add_command(char *dir_path, char *command)
{
	int len1, len2, a, b;
	char *command_path;

	if (dir_path == NULL || command == NULL)
		return (NULL);
	len1 = stringlen(dir_path);
	len2 = stringlen(command);

	/*Allocate memoryconcatenated path (+1 for the '/' and +1 null terminator)*/
	command_path = (char *)malloc(len1 + len2 + 2);

	if (command_path == NULL)
		return (NULL);
	for (a = 0; a < len1; a++)
		command_path[a] = dir_path[a];

	if (dir_path[a - 1] != '/')
	{
		command_path[a] = '/';
		a++;
	}
	for (b = 0; b < len2; b++)
		command_path[a + b] = command[b];

	command_path[a + b] = '\0';

	return (command_path);
}
