/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/10 19:27:13 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/16 17:03:56 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	len_arr(void **elements)
{
	size_t	i;

	i = 0;
	if (!elements)
		return (i);
	while (elements[i])
		i++;
	return (i);
}

mlx_texture_t	*load_png(t_game *game, char *file)
{
	mlx_texture_t	*img;

	img = mlx_load_png(file);
	if (!img)
		init_error(game, "Faild to load the image");
	return (img);
}

mlx_image_t	*to_png(t_game *game, mlx_texture_t **textu, int i)
{
	mlx_image_t	*img;

	img = mlx_texture_to_image(game->mlx, textu[i]);
	if (!img)
	{
		init_error(game, "Could not convert to IMG!");
		while (textu[i])
		{
			mlx_delete_texture(textu[i]);
			i++;
		}
	}
	else
		mlx_delete_texture(textu[i]);
	return (img);
}

int	sl_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}
