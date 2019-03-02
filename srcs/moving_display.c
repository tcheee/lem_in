/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:02:40 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/01 20:21:30 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		moving_display(t_farm *farm)
{
	int flow;
	int i;
	int start;
	int end;
	int j;
	int k;

	if (farm->optionp == 1)
		ft_printf("\n");
	i = 0;
	while (farm->room[i].start != 1) // find start, to put in a function and do the same for find end
		i++;
	start = i;
	i = 0;
	while (farm->room[i].end != 1)
		i++;
	end = i;

	while (graph_finished(farm) != 1)
	{
		flow = 0;
		i = 0;
		while (farm->room[start].ant >= flow && i < farm->nb_path)
			flow += farm->path[i++].weight;
		//ft_printf("we are going to use %d paths\n", i);
		j = 0;
		//ft_printf("\nThe number of ants in start is %d\n", farm->room[start].ant);
		//ft_printf("The number of ants in end is %d\n\n", farm->room[end].ant);
		while (j < farm->nb_path)
		{
			k = farm->path[j].weight - 1;
			while (k > 0)
			{
				//ft_printf("\nk = %d et index dans path est %s\n", k, farm->room[farm->path[j].path[k]].name);
				if (farm->room[farm->path[j].path[k - 1]].ant > 0)
				{
					move_ant(&farm->room[farm->path[j].path[k - 1]], &farm->room[farm->path[j].path[k]], farm);
					ft_printf("L%d-%s ", farm->room[farm->path[j].path[k]].ant_name, farm->room[farm->path[j].path[k]].name);
				}
				k--;
			}
			j++;
		}
		farm->counter++;
		ft_printf("\n");
	}
	if (farm->optionc == 1)
		ft_printf("\nNumber of turns : %d\n", farm->counter);
	return (1);
}
