/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_queue.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 20:15:16 by lvan-gef      #+#    #+#                 */
/*   Updated: 2024/05/05 22:42:15 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	enqueue(t_bfs *q, t_node *node)
{
	q->nodes[q->rear] = *node;
	q->rear++;
}

t_node	dequeue(t_bfs *q)
{
	t_node	node;

	node = q->nodes[q->front];
	q->front++;
	return (node);
}

bool	is_empty(t_bfs *q)
{
	return (q->front == q->rear);
}

int	is_valid(t_game *game, t_node node)
{
	if (node.row > 0 && node.row < game->rows
		&& node.col > 0 && node.col < game->cols)
	{
		if (game->map[node.row][node.col] == '1' ||
			game->map[node.row][node.col] == 'X')
			return (0);
		return (1);
	}
	return (0);
}

t_node	*find_neighbors(t_game *game, t_bfs *q, t_node current, int dir)
{
	t_node	*neighbor;

	if (dir == 0)
		neighbor = create_node(current.row - 1, current.col);
	else if (dir == 1)
		neighbor = create_node(current.row, current.col + 1);
	else if (dir == 2)
		neighbor = create_node(current.row + 1, current.col);
	else
		neighbor = create_node(current.row, current.col - 1);
	if (!neighbor)
	{
		path_error(game, q, "Faild to create a node, malloc ofc");
		return (NULL);
	}
	if (is_valid(game, *neighbor))
		return (neighbor);
	free(neighbor);
	return (NULL);
}
