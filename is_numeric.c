#include "main.h"
/**
 *is_numeric - is the number numeric
 *@str:argument
 * Return:1
 */
int is_numeric(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
