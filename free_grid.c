#include <stdlib.h>
#include <time.h>
#include "main.h"

/**
* free_grid -  Entrypoint
* Description: The program's description free_grid
* @grid : 1 param
*  Return: always 0 (Success)
*/
void free_grid(char **grid)
{
	int i;

	if (grid != NULL)
	{
		for (i = 0; grid[i] != NULL; i++)
		{
			free(grid[i]);
			grid[i] = NULL;
		}
		free(grid);
		grid = NULL;
	}
}

/**
* free_path -  Entrypoint
* Description: The program's description free_grid
* @grid : 1 param
*  Return: always 0 (Success)
*/
void free_path(char **grid)
{
	int i;

	if (grid != NULL)
	{
		for (i = 0; grid[i] != NULL; i++)
		{
			free(grid[i]);
			grid[i] = NULL;
		}
		free(grid);
		grid = NULL;
	}
}
