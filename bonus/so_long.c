/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 13:58:30 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/14 20:33:41 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		init_error(NULL, "Need 1 map to play it!!");
	game = init_game();
	read_map(game, argv[1]);
	valid_map(game);
	find_path(game);
	game->mlx = mlx_init(game->cols * game->img_s,
			((game->rows - 1) * game->img_s) + game->img_s, "So Long", false);
	if (!game->mlx)
		init_error(game, "MLX faild to init!");
	check_resolution(game);
	init_assets(game);
	run_game(game);
	return (0);
}
