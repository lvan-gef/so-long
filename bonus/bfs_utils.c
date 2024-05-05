/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 20:20:05 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/05 23:29:09 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_node	*create_node(int row, int col)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->row = row;
	node->col = col;
	return (node);
}

bool	**create_visited(const t_game *game)
{
	bool	**visited;
	int		i;

	visited = ft_calloc(game->rows + 1, sizeof(bool *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < game->rows)
	{
		visited[i] = ft_calloc(game->cols + 1, sizeof(bool));
		if (!visited[i])
		{
			bfs_free_nodes((void **)visited);
			return (NULL);
		}
		i++;
	}
	return (visited);
}
