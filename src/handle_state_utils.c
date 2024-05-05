/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_state_utils.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/16 19:54:18 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/16 21:09:18 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	animation(t_game *game, int indx)
{
	if (game->assets[indx]->instances)
	{
		if (game->assets[indx]->instances[0].enabled)
		{
			disable_player(game);
			return (enable_player(game, indx + 1));
		}
		else
		{
			disable_player(game);
			return (enable_player(game, indx));
		}
	}
	else
	{
		disable_player(game);
		return (enable_player(game, indx));
	}
	return (0);
}

void	disable_player(t_game *game)
{
	int	i;

	i = 4;
	while (i < game->img_c)
	{
		if (game->assets[i]->instances)
		{
			if (game->assets[i]->instances[0].enabled)
				game->assets[i]->instances[0].enabled = false;
		}
		i++;
	}
}

int	enable_player(t_game *game, int index)
{
	if (!game->assets[index]->instances)
		render_item(game, game->assets[index], game->px, game->py);
	else
	{
		game->assets[index]->instances[0].x = game->px * game->img_s;
		game->assets[index]->instances[0].y = game->py * game->img_s;
		game->assets[index]->instances[0].enabled = true;
	}
	return (index);
}

int	idle_player(t_game *game, int indx)
{
	disable_player(game);
	enable_player(game, indx - 1);
	return (indx);
}
