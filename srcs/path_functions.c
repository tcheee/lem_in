/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:39:20 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/15 22:35:08 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		create_path(int **path, int *queue, t_farm *farm, int nb)
{
	int weight;
	int room_after;
	int j;

	weight = nb;
	nb--;
	farm->count--;
	(*path)[nb] = queue[farm->count];
	j = nb - 1;
	room_after = queue[farm->count];
	while (farm->count >= 0)
	{
		if (farm->room[queue[farm->count]].weight == weight - 1
				&& farm->link[queue[farm->count]][room_after] == 1)
		{
			farm->link[queue[farm->count]][room_after] = -1;
			farm->link[room_after][queue[farm->count]] = -1;
			(*path)[j] = queue[farm->count];
			room_after = queue[farm->count];
			weight = farm->room[queue[farm->count]].weight;
			j--;
		}
		nb--;
		farm->count--;
	}
}

int			path_found(t_farm *farm, int **queue, int end, int vertex)
{
	farm->room[end].weight = farm->room[vertex].weight + 1;
	if (!(farm->path[farm->nb_path].path =
				ft_memalloc(sizeof(int*) * (farm->room[end].weight))))
		return (-1);
	create_path(&farm->path[farm->nb_path].path, *queue, farm, farm->room[end].weight);
	farm->path[farm->nb_path].weight = farm->room[end].weight;
	farm->path[farm->nb_path].c_weight = farm->room[end].weight - 1;
	farm->path[farm->nb_path].ants_to_send = 0;
	if (farm->optionp == 1)
	{
		ft_printf("Path[%d] has a weight of %d and is: ",
				farm->nb_path,farm->path[farm->nb_path].c_weight);
		print_path(farm->path[farm->nb_path].path, farm->room[end].weight, farm);
	}
	free(*queue);
	return (1);
}
