/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/05 22:06:20 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/10 19:25:59 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_item(t_game *game, mlx_image_t *img,
		size_t col, size_t row)
{
	mlx_image_to_window(game->mlx, img, col * game->img_s, row * game->img_s);
}

static	void	render_element(t_game *game, char *str)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->cols)
		{
			if (!ft_strncmp(str, "bg", 2))
				render_item(game, game->assets[0], col, row);
			else if (!ft_strncmp(str, "wl", 2) && game->map[row][col] == '1')
				render_item(game, game->assets[1], col, row);
			else if (!ft_strncmp(str, "cl", 2) && game->map[row][col] == 'C')
				render_item(game, game->assets[2], col, row);
			else if (!ft_strncmp(str, "ex", 2) && game->map[row][col] == 'E')
				render_item(game, game->assets[3], col, row);
			else if (!ft_strncmp(str, "pl", 2) && game->map[row][col] == 'P')
				render_item(game, game->assets[4], col, row);
			col++;
		}
		row++;
	}
}

static void	render_map(t_game *game)
{
	render_element(game, "bg");
	render_element(game, "wl");
	render_element(game, "cl");
	render_element(game, "ex");
	render_element(game, "pl");
}

void	run_game(t_game *game)
{
	render_map(game);
	mlx_key_hook(game->mlx, &my_keyhook, (void *)game);
	mlx_loop(game->mlx);
	return ;
}
