/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ant.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:02:40 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/03 16:08:18 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*static void		loop_algo(t_farm *farm, int *j)
  {
  int k;

  while (*j < farm->nb_path)
  {
  k = farm->path[*j].weight - 1;
  while (k > 0)
  {
  if (farm->room[farm->path[*j].path[k - 1]].ant > 0)
  {
  move_ant(&farm->room[farm->path[*j].path[k - 1]],
  &farm->room[farm->path[*j].path[k]], farm);
  ft_printf("L%d-%s ", farm->room[farm->path[*j].path[k]].ant_name, farm->room[farm->path[*j].path[k]].name);
  }
  k--;
  }
  (*j)++;
  }
  }*/

int				moving_display(t_farm *farm) //implement a dispatcher for the ants
{
	int start;
	int end;
	int j;
	int k;
	int	e;

	if (farm->optionp == 1)
		ft_printf("\n");
	start = find_start(farm);
	end = find_end(farm);
	while (graph_finished(farm) != 1)
	{
		//red pill
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
			e = farm->path[0].weight + farm->room[start].ant + 1;
			j = 0;
			while (j < farm->nb_path)
			{
				e--;
				//ft_printf("\ne = %d and the weight of the path test is %d\n", e, farm->path[j].weight);
				if (e >= farm->path[j].weight)
				{
					k = 0;
					while (k < 1)
					{
						if (farm->room[farm->path[j].path[k + 1]].ant == 0)
						{
							move_ant(&farm->room[farm->path[j].path[k]], &farm->room[farm->path[j].path[k + 1]], farm);
							ft_printf("L%d-%s ", farm->room[farm->path[j].path[k + 1]].ant_name, farm->room[farm->path[j].path[k + 1]].name);
						}
						k++;
					}
				}
				j++;
			}
		}
		//loop_algo(farm, &j);
		farm->counter++;
		ft_printf("\n");
	}
	if (farm->optionc == 1)
		ft_printf("\nNumber of turns : %d\n", farm->counter);
	return (1);
}
