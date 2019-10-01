/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:26:35 by adavis            #+#    #+#             */
/*   Updated: 2019/10/01 17:12:50 by cpollich         ###   ########.fr       */
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
		i = lem->size - 1;
		while (i >= 0)
		{
			if (lem->smezh[index][i] == 1)
			{
				cnt++;
				index = i;
				break ;
			}
			i--;
		}
	}
	return (cnt);
}
