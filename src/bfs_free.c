/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_free.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-gef <lvan-gef@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 20:16:36 by lvan-gef      #+#    #+#                 */
/*   Updated: 2023/04/13 21:18:24 by lvan-gef      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	bfs_free_nodes(void **nodes)
{
	int	i;

	if (nodes)
	{
		i = 0;
		while (nodes[i])
		{
			free(nodes[i]);
			i++;
		}
		free(nodes);
	}
}

int	bfs_free_q(t_bfs *bfs)
{
	if (bfs)
	{
		if (bfs->nodes)
			free(bfs->nodes);
		if (bfs->visited)
			bfs_free_nodes((void **)bfs->visited);
		free(bfs);
	}
	return (1);
}
