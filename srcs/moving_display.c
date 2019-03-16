/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:02:40 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/15 17:54:23 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			do_the_math(t_farm *farm)
{
	int	index;
	int	total;
	int	k;

	index = 0;
	total = farm->total;
	while (total > 0)
	{
		k = 0;
		while (k <= index && total > 0)
		{
			farm->path[k].ants_to_send++;
			total--;
			k++;
			if (index < farm->nb_path - 1 && (farm->path[index].ants_to_send + farm->path[index].c_weight >= farm->path[index + 1].c_weight))
				index++;
		}
	}
	k = -1;
	while (++k < farm->nb_path)
		ft_printf("The weight for the path is %d, and we send %d ants to path[%d]\n", farm->path[k].c_weight, farm->path[k].ants_to_send, k);
	ft_printf("We use %d paths\n\n", index + 1);
}

int					moving_display(t_farm *farm)
{
	int	start;
	int	used;
	int	k;
	int j;

	used = 0;
	if (farm->optionp == 1)
		ft_printf("The number of path is : %d\n\n", farm->nb_path);
	start = find_start(farm);
	do_the_math(farm);
	while (farm->path[used].ants_to_send > 0)
		used++;
	while (graph_finished(farm) != 1)
	{
		k = 0;
		while (k <= used)
		{
			j = farm->path[k].weight - 1;
			while (j > 1)
			{
				if (farm->room[farm->path[k].path[j - 1]].ant == 1)
				{
					move_ant(&farm->room[farm->path[k].path[j - 1]], &farm->room[farm->path[k].path[j]], farm);
					ft_printf("WTFL%d-%s ", farm->room[farm->path[k].path[j]].ant_name, farm->room[farm->path[k].path[j]].name);
				}
				j--;
			}
			if (farm->path[k].ants_to_send > 0)
			{
				if (farm->room[farm->path[k].path[1]].ant == 0)
				{
					move_ant(&farm->room[farm->path[k].path[0]], &farm->room[farm->path[k].path[1]], farm);
					farm->path[k].ants_to_send--;
					ft_printf("L%d-%s ", farm->room[farm->path[k].path[1]].ant_name, farm->room[farm->path[k].path[1]].name);
				}
			}
			k++;
		}
		farm->counter++;
		ft_printf("\n");
	}
	if (farm->optionc == 1)
		ft_printf("\nNumber of turns : %d\n", farm->counter);
	return (1);
}
