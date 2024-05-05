/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/05 22:00:38 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/16 16:41:25 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_left(t_game *game)
{
	int	player_indx;

	if (game->px - 1 == 0)
	{
		handle_player(game, 65);
		return ;
	}
	if (game->map[game->py][game->px - 1] == '1')
		return ;
	player_indx = handle_player(game, 65);
	if (player_indx)
	{
		game->counter += 1;
		game->assets[player_indx]->instances[0].x -= game->img_s;
		game->px--;
		update_txt(game);
	}
	handle_state(game);
}

static void	move_up(t_game *game)
{
	int	player_indx;

	if (game->py - 1 == 0)
	{
		handle_player(game, 87);
		return ;
	}
	if (game->map[game->py - 1][game->px] == '1')
		return ;
	player_indx = handle_player(game, 87);
	if (player_indx)
	{
		game->counter += 1;
		game->assets[player_indx]->instances[0].y -= game->img_s;
		game->py--;
		update_txt(game);
	}
	handle_state(game);
}

static void	move_down(t_game *game)
{
	int	player_indx;

	if (game->py + 1 == game->rows - 1)
	{
		handle_player(game, 83);
		return ;
	}
	if (game->map[game->py + 1][game->px] == '1')
		return ;
	player_indx = handle_player(game, 83);
	if (player_indx)
	{
		game->counter += 1;
		game->assets[player_indx]->instances[0].y += game->img_s;
		game->py++;
		update_txt(game);
	}
	handle_state(game);
}

static void	move_right(t_game *game)
{
	int	player_indx;

	if (game->px + 1 == game->cols - 1)
	{
		handle_player(game, 68);
		return ;
	}
	if (game->map[game->py][game->px + 1] == '1')
		return ;
	player_indx = handle_player(game, 68);
	if (player_indx)
	{
		game->counter += 1;
		game->assets[player_indx]->instances[0].x += game->img_s;
		game->px++;
		update_txt(game);
	}
	handle_state(game);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_A)
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			move_left(game);
	if (keydata.key == MLX_KEY_W)
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			move_up(game);
	if (keydata.key == MLX_KEY_S)
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			move_down(game);
	if (keydata.key == MLX_KEY_D)
		if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
			move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE)
		stop_game(game, 0);
}
