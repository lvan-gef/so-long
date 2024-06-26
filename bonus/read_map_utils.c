/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/16 16:57:26 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/05 23:36:31 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	add_spacing(t_game *game, char *line, int fd)
{
	size_t	i;
	size_t	len;
	size_t	size;

	size = len_arr((void **)game->map);
	if (size != 1)
		return ;
	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		game->map[0][i] = '1';
		i++;
	}
	game->map[size] = ft_calloc(game->cols + 1, sizeof(char));
	if (!game->map[size])
		build_error(game, "Faild to get mem for a new row", line, fd);
}
