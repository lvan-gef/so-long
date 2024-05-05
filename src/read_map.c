/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 15:37:59 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/10 19:24:58 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	char	**copy_map(t_game *game, char **map, int fd, size_t size)
{
	size_t	i;

	i = 0;
	while (game->map[i])
	{
		map[i] = ft_calloc(game->cols + 1, sizeof(char));
		if (!map[i])
		{
			map = sl_free_map(map);
			game->map = sl_free_map_i(game, i);
			build_error(game, "Faild to make the new map 1", NULL, fd);
			return (map);
		}
		ft_strlcpy(map[i], game->map[i], game->cols + 1);
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = map;
	game->rows = size + 1;
	return (map);
}

static	void	expend_map(t_game *game, char *line, int fd)
{
	size_t	size;
	char	**map;

	if (!game->map)
	{
		game->map = ft_calloc(2, sizeof(char *));
		if (!game->map)
			build_error(game, "Expand failed, malloc failed", line, fd);
		return ;
	}
	size = len_arr((void **)game->map);
	map = ft_calloc(size + 2, sizeof(char *));
	if (map)
	{
		copy_map(game, map, fd, size);
		if (!map)
			build_error(game, "Faild to make the new map", line, fd);
		return ;
	}
	build_error(game, "Could not expand map because off malloc fail", line, fd);
}

static void	create_row(t_game *game, char *line, int fd)
{
	size_t	size;

	expend_map(game, line, fd);
	if (!game->map)
		build_error(game, "Faild to create a row", line, fd);
	else
	{
		size = len_arr((void **)game->map);
		game->map[size] = ft_calloc(game->cols + 1, sizeof(char));
		if (!game->map[size])
			build_error(game, "Faild to get mem for a new row", line, fd);
		else
		{
			ft_strlcpy(game->map[size], line, ft_strlen(line) + 1);
			free(line);
		}
	}
}

static	void	build_map(t_game *game, int fd)
{
	char	*raw_line;
	char	*line;

	raw_line = get_next_line(fd);
	while (raw_line)
	{
		line = ft_strtrim(raw_line, "\n");
		if (!line)
			build_error(game, "Error while trimming line", raw_line, fd);
		else
		{
			free(raw_line);
			if (!game->cols)
				game->cols = sl_strlen(line);
			if (game->cols != sl_strlen(line))
				build_error(game, "Rows are not the same lenght", line, fd);
			else
				create_row(game, line, fd);
		}
		raw_line = get_next_line(fd);
	}
	close(fd);
	if (!game->map)
		init_error(game, "The map is empty");
}

void	read_map(t_game *game, char *file)
{
	int		fd;
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext)
		init_error(game, "Invalid file name!");
	else
	{
		ext++;
		if (!ft_strnstr("ber", ext, 3))
			init_error(game, "The file did not end with .ber!");
		else
		{
			fd = open(file, O_RDONLY);
			if (fd < 0)
			{
				close(fd);
				init_error(game, "Could not read the file!");
			}
			else
				build_map(game, fd);
		}
	}
}
