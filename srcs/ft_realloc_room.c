/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:42:22 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/03 10:41:16 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_realloc_room(t_farm *farm, int old_nb_room)
{
	int		j;
	t_room	*tmp;

	j = 0;
	ft_printf("previous farm_size = %d\n", farm->size);
	if (!(tmp = malloc(sizeof(t_room) * (farm->size * 2))))
		return (-1);
	farm->size = farm->size * 2;
	while (j < old_nb_room)
	{
		tmp[j] = farm->room[j];
		j++;
	}
	ft_printf("new farm_size = %d\n", farm->size);
	ft_printf("reallocation is done\n");
	//free(farm.room);
	farm->room = tmp;
	return (0);
}
