/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_resolution.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 18:07:28 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/16 16:53:12 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	set_window_pos(t_game *game)
{
	int	start_x;
	int	start_y;

	start_x = (game->mlx->width - (game->cols * game->img_s)) / 2;
	start_y = (game->mlx->height - (game->rows * game->img_s)) / 2;
	mlx_set_window_pos(game->mlx, start_x, start_y);
}

void	check_resolution(t_game *game)
{
	int	img_size;

	img_size = game->img_s;
	mlx_get_monitor_size(0, &game->mlx->width, &game->mlx->height);
	while (game->rows * img_size > game->mlx->height && img_size >= 8)
		img_size /= 2;
	while (game->cols * img_size > game->mlx->width && img_size >= 8)
		img_size /= 2;
	game->img_s = img_size;
	if (img_size < 8)
		init_error(game, "Map is to big to display");
	else
	{
		set_window_pos(game);
		mlx_set_window_size(game->mlx,
			game->cols * game->img_s,
			game->rows * game->img_s);
	}
}
