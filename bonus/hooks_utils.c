/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/16 16:42:55 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/16 17:56:23 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_txt(t_game *game)
{
	char	*nbr;

	if (game->display_c)
		mlx_delete_image(game->mlx, game->display_c);
	nbr = ft_itoa(game->counter);
	if (!nbr)
		return ;
	game->display_c = mlx_put_string(game->mlx, nbr,
			(game->cols / 2) * game->img_s,
			(game->img_s / 2) - ((game->img_s / 2) / 2));
	free(nbr);
}

void	set_txt(t_game *game)
{
	if (game->display_c)
		mlx_delete_image(game->mlx, game->display_c);
	game->display_c = mlx_put_string(game->mlx,
			"Game Over",
			(game->cols / 2) * game->img_s,
			(game->img_s / 2) - ((game->img_s / 2) / 2));
}
