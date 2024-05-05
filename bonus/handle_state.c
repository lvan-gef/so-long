/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   state_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/05 21:27:45 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/16 16:38:59 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	handle_collects(t_game *game, int row, int col)
{
	int	i;

	i = 0;
	while (i < game->assets[2]->count)
	{
		if (game->assets[2]->instances[i].y / game->img_s == row)
		{
			if (game->assets[2]->instances[i].x / game->img_s == col)
			{
				game->assets[2]->instances[i].enabled = false;
				break ;
			}
		}
		i++;
	}
}

static	int	swap_player(t_game *game, int dir)
{
	if (dir == 65)
	{
		if (game->px > 1)
			return (animation(game, 5));
		return (idle_player(game, 5));
	}
	else if (dir == 87)
	{
		if (game->py > 1)
			return (animation(game, 8));
		return (idle_player(game, 8));
	}
	else if (dir == 83)
	{
		if (game->py < game->rows - 2)
			return (animation(game, 11));
		return (idle_player(game, 11));
	}
	else if (dir == 68)
	{
		if (game->px < game->cols - 2)
			return (animation(game, 14));
		return (idle_player(game, 14));
	}
	return (0);
}

int	handle_player(t_game *game, int dir)
{
	int	index;

	if (game->dir == dir)
		return (swap_player(game, dir));
	index = 0;
	if (dir == 65)
		index = 4;
	else if (dir == 87)
		index = 7;
	else if (dir == 83)
		index = 10;
	else if (dir == 68)
		index = 13;
	if (!index)
		return (0);
	disable_player(game);
	enable_player(game, index);
	game->dir = dir;
	return (0);
}

int	handle_state(t_game *game)
{
	size_t	col;
	size_t	row;

	col = game->px;
	row = game->py;
	if (game->map[row][col] == 'C' && game->c > 0)
	{
		game->map[row][col] = '0';
		handle_collects(game, row, col);
		game->c--;
		return (0);
	}
	if (game->map[row][col] == 'X')
	{
		set_txt(game);
		stop_game(game, 1);
	}
	if (game->map[row][col] == 'E' && game->c == 0)
		stop_game(game, 0);
	return (0);
}
