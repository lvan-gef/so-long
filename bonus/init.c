/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/28 13:51:06 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/16 16:50:27 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_state(t_game *game)
{
	game->px = 0;
	game->py = 0;
	game->c = 0;
	game->e = 0;
	game->rows = 0;
	game->cols = 0;
	game->counter = 0;
	game->dir = 65;
	game->img_s = 64;
	game->img_c = 17;
	game->map = NULL;
	game->src_img = NULL;
	game->mlx = NULL;
	game->assets = NULL;
	game->display_c = NULL;
}

static	mlx_texture_t	**init_textures(t_game *game)
{
	mlx_texture_t		**tp;
	int					i;

	tp = ft_calloc(game->img_c + 1, sizeof(mlx_texture_t *));
	if (!tp)
		init_error(game, "Malloc faild to get the mem!");
	else
	{
		i = 0;
		while (i < game->img_c)
		{
			tp[i] = load_png(game, game->src_img[i]);
			i++;
		}
	}
	return (tp);
}

void	init_assets(t_game *game)
{
	mlx_image_t		**imgs;
	mlx_texture_t	**textu;
	size_t			i;
	size_t			len_assets;

	imgs_path(game);
	textu = init_textures(game);
	len_assets = len_arr((void **)textu);
	imgs = ft_calloc(len_assets + 1, sizeof(mlx_image_t *));
	if (!imgs)
		init_error(game, "Malloc faild to get the mem!");
	else
	{
		i = 0;
		while (i < len_assets)
		{
			imgs[i] = to_png(game, textu, i);
			i++;
		}
		free(textu);
		game->assets = imgs;
	}
}

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		init_error(NULL, "Malloc faild to get the mem!");
	init_state(game);
	return (game);
}
