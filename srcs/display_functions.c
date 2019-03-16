/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:37:46 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/15 16:53:05 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_path(int *path, int nb, t_farm *farm)
{
	int i;

	i = -1;
	while (++i < nb)
		ft_printf("%s ", farm->room[path[i]].name);
	ft_printf("\n");
}
