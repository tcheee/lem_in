/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:51:03 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/15 22:42:05 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		reset_before_bfs(t_farm *farm)
{
	int i;

	i = -1;
	while (++i < farm->nb_room)
		farm->room[i].visited = 0;
	farm->first = -1;
	farm->last = -1;
}

static void		initialization_bfs(t_farm *farm, int **queue, int *end)
{
	int i;

	farm->nb_queue = 0;
	i = find_start(farm);
	farm->room[i].weight = 1;
	enqueue(i, queue, farm);
	farm->count = 1;
	*end = find_end(farm);
}

static void		gain_space(t_farm *farm, int **queue, int i, int vertex)
{
	farm->count++;
	enqueue(i, queue, farm);
	farm->nb_queue++;
	farm->room[i].weight = farm->room[vertex].weight + 1;
}

static void		prepare_loop(t_farm *farm, int **queue, int *vertex, int *i)
{
	*vertex = dequeue(queue, farm);
	put_vertex_visited(*vertex, farm);
	*i = -1;
}

int				bfs(t_farm *farm)
{
	int		*queue;
	int		i;
	int		vertex;
	int		end;
	int		start;
	int		check;
	int		j;

	reset_before_bfs(farm);
	if (!(queue = ft_memalloc(sizeof(int*) * farm->nb_room)))
		return (-1);
	initialization_bfs(farm, &queue, &end);
	start = find_start(farm);
	while (!is_empty(farm))
	{
		prepare_loop(farm, &queue, &vertex, &i);
		check = 0;
		j = -1;
		while (++j < farm->nb_room)
			if (vertex != start && j != start && farm->link[vertex][j] == -1)
				check = 1;
		while (++i < farm->nb_room)
		{
			if (check == 0 && farm->link[vertex][i] == 1 && farm->room[i].visited == 0)
			{
				if (check_enqueue(queue, i, farm) == 1)
					gain_space(farm, &queue, i, vertex);
				if (i == end)
					return (path_found(farm, &queue, end, vertex));
			}
		}
	}
	free(queue);
	return (0);
}
