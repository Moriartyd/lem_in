/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:26:35 by adavis            #+#    #+#             */
/*   Updated: 2019/09/26 18:26:37 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		pathlen(t_lemin *lem, int index)
{
	int		i;
	int		cnt;

	cnt = 1;
	while (lem->end->index != index)
	{
		i = -1;
		while (++i < lem->size)
		{
			if (lem->smezh[index][i] == 1)
			{
				cnt++;
				index = i;
				break ;
			}
		}
	}
	return (cnt);
}
