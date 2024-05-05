/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_me.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 13:46:49 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/13 17:31:52 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**sl_free_map(char **map)
{
	size_t	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	return (NULL);
}

char	**sl_free_map_i(t_game *game, int i)
{
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	return (NULL);
}

static void	sl_free_assets(t_game *game)
{
	size_t	len_assets;
	size_t	i;

	len_assets = len_arr((void **)game->assets);
	i = 0;
	while (i < len_assets)
	{
		mlx_delete_image(game->mlx, game->assets[i]);
		i++;
	}
	free(game->assets);
}

void	sl_free_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			game->map = sl_free_map(game->map);
		if (game->assets)
			sl_free_assets(game);
		if (game->src_img)
			sl_free_map(game->src_img);
	}
}
