#include "main.h"
/**
 * last_dealloc - Free the memory for the last execution
 * @entry: Input typed by the user
 */
void last_dealloc(char *entry)
{
	if (entry == NULL)
		return;
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		free(entry);
	}
	else
	{
		free(entry);
	}
}
