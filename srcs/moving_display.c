/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:02:40 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/03 18:45:21 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			do_the_math(t_farm *farm)
{
}

/*static void			red_pill(t_farm *farm)
{
	int j;
	int k;

	j = 0;
	while (j < farm->nb_path)
	{
		k = farm->path[j].weight - 1;
		while (k > 1)
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

}

static void			blue_pill(t_farm *farm)
{
	int j;

	j = 0;
	while (j < farm->nb_path)
	{
		if (farm->path[j].ants_send > 0)
		{
			if (farm->room[farm->path[j].path[1]].ant == 0)
			{
				move_ant(&farm->room[farm->path[j].path[0]], &farm->room[farm->path[j].path[1]], farm);
				ft_printf("L%d-%s ", farm->room[farm->path[j].path[1]].ant_name, farm->room[farm->path[j].path[1]].name);
			}
		}
		j++;
	}
}*/

int					moving_display(t_farm *farm) //implement a dispatcher for the ants
{
	int start;
	int j; // to delete
	int k; // to delete

	if (farm->optionp == 1)
		ft_printf("\n");
	start = find_start(farm);
	do_the_math(farm);
	while (graph_finished(farm) != 1)
	{
		//red_pill(farm);
		j = 0;
		while (j < farm->nb_path)
		{
			k = farm->path[j].weight - 1;
			while (k > 1)
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

		//blue pill
		if (farm->room[start].ant > 0)
		{ 
			//blue_pill(farm);
			j = 0;
			while (j < farm->nb_path)
			{
				if (farm->path[j].ants_send > 0)
				{
					if (farm->room[farm->path[j].path[1]].ant == 0)
					{
						move_ant(&farm->room[farm->path[j].path[0]], &farm->room[farm->path[j].path[1]], farm);
						ft_printf("L%d-%s ", farm->room[farm->path[j].path[1]].ant_name, farm->room[farm->path[j].path[1]].name);
					}
				}
				j++;
			}
		}
		farm->counter++;
		ft_printf("\n");
	}
	if (farm->optionc == 1)
		ft_printf("\nNumber of turns : %d\n", farm->counter);
	return (1);
}
