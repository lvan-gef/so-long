/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 14:00:51 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/05 23:15:59 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	only_walls(t_game *game, const char *row, int cols)
{
	int	col;

	col = 0;
	while (col < cols)
	{
		if (!ft_strchr("1", row[col]))
		{
			init_error(game, "Top or bottom row is not only walls");
			return (0);
		}
		col++;
	}
	return (1);
}

int	check_row(t_game *game, const char *row, int cols)
{
	int	col;

	col = 0;
	while (col < cols)
	{
		if (col == 0 || col == cols - 1)
		{
			if (!ft_strchr("1", row[col]))
			{
				init_error(game, "First or last element in row is not a wall!");
				return (0);
			}
		}
		else
		{
			if (!ft_strchr("10CEP", row[col]))
			{
				init_error(game, "Element in row is not allowed!");
				return (0);
			}
		}
		col++;
	}
	return (1);
}

static int	check_elements(t_game *game, const char *row, int row_c)
{
	int	col;

	col = 0;
	while (col < game->cols)
	{
		if (row[col] == 'E')
			game->e += 1;
		else if (row[col] == 'P')
		{
			if (game->py || game->px)
			{
				init_error(game, "To many players!");
				return (0);
			}
			game->py = row_c;
			game->px = col;
		}
		else if (row[col] == 'C')
			game->c += 1;
		col++;
	}
	return (1);
}

static	void	check_result(t_game *game, int row)
{
	if (row == 0 || row == game->rows - 1)
	{
		if (!only_walls(game, game->map[row], game->cols))
			init_error(game, "Top or Bottom row is nor only walls");
	}
	else
	{
		if (!check_row(game, game->map[row], game->cols))
			init_error(game, "Row is invalid");
		else
		{
			if (!check_elements(game, game->map[row], row))
				init_error(game, "Map is invalid");
		}
	}
}

void	valid_map(t_game *game)
{
	int	row;

	row = 0;
	while (row < game->rows)
	{
		check_result(game, row);
		row++;
	}
	if (game->e > 1 || game->c < 1 || !game->py || !game->px)
		init_error(game, "Not all elements are there or to much off them");
}
