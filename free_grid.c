#include "main.h"
/**
 * dealloc - Free the allocated memory used in the last exercise
 * @grid: pointer to grid
 * @height: Height of the grid
 */
void dealloc(char **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;
	for (i = 0; i < height; i++)
	{
		if (grid[i] != NULL)
		free(grid[i]);
	}
	free(grid);
}
