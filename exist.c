#include "main.h"
/**
 * isthere - Verify if a file exists
 * @pathname: path to the file
 * Return: 0 if the file exists, or -1 if not
 */
int isthere(char *pathname)
{
	if (access(pathname, F_OK) == 0)
		return (0);
	else
		return (-1);
}
