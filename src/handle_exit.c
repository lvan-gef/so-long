/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_exit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/05 21:55:31 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/13 21:20:13 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	stop_game(t_game *game, int errc)
{
	if (game)
	{
		if (game->mlx)
		{
			mlx_close_window(game->mlx);
			mlx_terminate(game->mlx);
		}
		sl_free_game(game);
		free(game);
	}
	exit(errc);
}

void	init_error(t_game *game, char *msg)
{
	ft_printf("Error:\n\t%s\n", msg);
	stop_game(game, 1);
}

void	build_error(t_game *game, char *msg, char *line, int fd)
{
	if (fd)
		close(fd);
	if (line)
		free(line);
	init_error(game, msg);
}

void	path_error(t_game *game, t_bfs *bfs, char *msg)
{
	bfs_free_q(bfs);
	init_error(game, msg);
}
