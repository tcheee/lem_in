/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 10:37:46 by tcherret          #+#    #+#             */
/*   Updated: 2019/03/02 10:38:22 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_path(int *path, int nb)
{
	int i;

	i = -1;
	while (++i < nb)
		ft_printf("%d ", path[i]);
	ft_printf("\n");
}
