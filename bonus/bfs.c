/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 20:15:10 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/13 21:19:47 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	void	bfs_neighbor(t_game *game, t_bfs *q, t_node current)
{
	t_node	*neighbor;
	int		i;

	i = 0;
	while (i < 4)
	{
		neighbor = find_neighbors(game, q, current, i);
		if (neighbor)
		{
			if (!q->visited[neighbor->row][neighbor->col])
			{
				q->visited[neighbor->row][neighbor->col] = true;
				enqueue(q, neighbor);
			}
			free(neighbor);
		}
		i++;
	}
}

static	int	bfs_loop(t_game *game, t_bfs *q, int collects, int find_exit)
{
	t_node	current;

	while (!is_empty(q))
	{
		current = dequeue(q);
		if (find_exit)
		{
			if (game->map[current.row][current.col] == 'E')
				return (bfs_free_q(q));
		}
		else
		{
			if (game->map[current.row][current.col] == 'C')
				collects--;
			if (!collects)
				return (bfs_free_q(q));
		}
		bfs_neighbor(game, q, current);
	}
	bfs_free_q(q);
	return (0);
}

static	int	bfs(t_game *game, t_node *start, int collects, int find_exit)
{
	t_bfs	*q;

	q = ft_calloc(1, sizeof(t_bfs));
	if (!q)
		path_error(game, NULL, "Faild to create the queue struct");
	q->visited = create_visited(game);
	if (!q->visited)
		path_error(game, q, "Faild to create the visited map");
	q->nodes = ft_calloc((game->rows * game->cols) + 1, sizeof(t_node));
	if (!q->nodes)
		path_error(game, q, "Faild to create the nodes map");
	q->front = 0;
	q->rear = 0;
	enqueue(q, start);
	q->visited[start->row][start->col] = true;
	return (bfs_loop(game, q, collects, find_exit));
}

int	find_path(t_game *game)
{
	t_node	*start;

	start = create_node(game->py, game->px);
	if (!start)
		path_error(game, NULL, "Faild to create the start node");
	if (bfs(game, start, game->c, 0))
	{
		if (bfs(game, start, 0, 1))
		{
			free(start);
			return (0);
		}
		free(start);
		path_error(game, NULL, "Exit is not reacheble");
	}
	else
	{
		free(start);
		path_error(game, NULL, "Not all collectebles are reacheble!");
	}
	return (0);
}
