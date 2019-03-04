/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:02:40 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/03 17:59:11 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			do_the_math(t_farm *farm)
{
	int current_path;
	int total_ants;
	int i;

	total_ants = farm->total;
	while (total_ants > 0)
	{
		i = 0;
		while (i < farm->nb_path)
		{
			if (farm->path[i].weight + farm->path[i].ants_send > farm->path[i + 1].weight)
				

		}
		//check the weight of the current_path we are checking
		//send one ant of the current_path
		//if the number of path's weight is greater the current_path weight with the ant
			//then keep adding ants to the current_path
		//otherwise, use the next path that has been found (current_path + 1)
		//if the number of ants to send is greater than 1
			//do math here...
		//decrement the total_ants and repeat until ants to send is zero
	}
}

int				moving_display(t_farm *farm) //implement a dispatcher for the ants
{
	int start;
	int end;
	int j;
	int k;

	if (farm->optionp == 1)
		ft_printf("\n");
	start = find_start(farm);
	end = find_end(farm);
	do_the_math(farm);
	while (graph_finished(farm) != 1)
	{


		j = 0;
		while (j < farm->nb_path)
		{
			k = farm->path[j].weight - 1;
			while (k > 0)
			{
				if (farm->room[farm->path[j].path[k - 1]].ant > 0)
				{
					move_ant(&farm->room[farm->path[j].path[k - 1]],
							&farm->room[farm->path[j].path[k]], farm);
					ft_printf("L%d-%s ", farm->room[farm->path[j].path[k]].ant_name, farm->room[farm->path[j].path[k]].name);
				}
				k--;
			}
			(j)++;


		}
		farm->counter++;
		ft_printf("\n");
	}
	if (farm->optionc == 1)
		ft_printf("\nNumber of turns : %d\n", farm->counter);
	return (1);
}
