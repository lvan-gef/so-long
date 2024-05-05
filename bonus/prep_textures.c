/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   prep_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/16 16:55:51 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/16 16:55:58 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	char	*real_path(t_game *game, char *suffix, char *filename)
{
	char	*fullname;

	fullname = ft_strjoin(suffix, filename);
	if (!fullname)
	{
		free(suffix);
		init_error(game, "Faild to make a path");
		return (NULL);
	}
	return (fullname);
}

static	void	set_paths(t_game *game, char *suffix)
{
	game->src_img[0] = real_path(game, suffix, "/ground_05.png");
	game->src_img[1] = real_path(game, suffix, "/crate_01.png");
	game->src_img[2] = real_path(game, suffix, "/environment_12.png");
	game->src_img[3] = real_path(game, suffix, "/environment_03.png");
	game->src_img[4] = real_path(game, suffix, "/player_a_idle.png");
	game->src_img[5] = real_path(game, suffix, "/player_a.png");
	game->src_img[6] = real_path(game, suffix, "/player_a_midle.png");
	game->src_img[7] = real_path(game, suffix, "/player_w_idle.png");
	game->src_img[8] = real_path(game, suffix, "/player_w.png");
	game->src_img[9] = real_path(game, suffix, "/player_w_midle.png");
	game->src_img[10] = real_path(game, suffix, "/player_s_idle.png");
	game->src_img[11] = real_path(game, suffix, "/player_s.png");
	game->src_img[12] = real_path(game, suffix, "/player_s_midle.png");
	game->src_img[13] = real_path(game, suffix, "/player_d_idle.png");
	game->src_img[14] = real_path(game, suffix, "/player_d.png");
	game->src_img[15] = real_path(game, suffix, "/player_d_midle.png");
	game->src_img[16] = real_path(game, suffix, "/enemy.png");
}

void	imgs_path(t_game *game)
{
	char	*suffix;
	char	*nbr;

	game->src_img = ft_calloc(game->img_c + 1, sizeof(char *));
	if (!game->src_img)
	{
		init_error(game, "Faild to make a paths list for img's");
		return ;
	}
	nbr = ft_itoa(game->img_s);
	if (!nbr)
	{
		init_error(game, "Faild to convert int to str");
		return ;
	}
	suffix = ft_strjoin("./textures/", nbr);
	free(nbr);
	if (!suffix)
	{
		init_error(game, "Faild to make all the paths");
		return ;
	}
	set_paths(game, suffix);
	free(suffix);
}
