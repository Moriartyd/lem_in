/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:38:31 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/26 21:47:39 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	min_link(t_lemin *lem, int index)
{
	int		pathlens[lem->size];
	int		i;
	int		min;
	int		min_link;

	i = -1;
	while (++i < lem->size)
	{
		if (lem->smezh[index][i] == 1)
			pathlens[i] = pathlen(lem, i);
		else
			pathlens[i] = -1;
	}
	i = -1;
	min = INT_MAX;
	while (++i < lem->size)
	{
		if (pathlens[i] > 0 && pathlens[i] < min)
		{
			min = pathlens[i];
			min_link = i;
		}
	}
	return (min_link);
}

static void	clean_outs(t_lemin *lem, int index)
{
	int		i;
	int		min;

	min = min_link(lem, index);
	i = -1;
	while (++i < lem->size)
	{
		if (lem->smezh[index][i] == 1 && i != min)
			lem->smezh[index][i] = 0;
	}
}

void		remove_output_forks(t_lemin *lem)
{
	int		lvl;
	int		flag;
	t_rooms	*rooms;

	lvl = find_final_room(lem)->room->level + 1;
	while (--lvl > 0)
	{
		rooms = lem->list;
		while (rooms)
		{
			if (rooms->room->level == lvl && rooms->room->out > 1)
				clean_outs(lem, rooms->room->index);
			rooms = rooms->next;
		}
	}
}

void		remove_input_forks(t_lemin *lem)
{
	int		i;
	int		j;
	int		current_level;
	int		flag;

	current_level = 0;
	flag = 1;
	while (flag)
	{
		current_level++;
		flag = 0;
		j = -1;
		while (++j < lem->size)
			if (find_room_ind(j, lem)->level == current_level)
			{
				flag = 1;
				if (find_room_ind(j, lem)->in > 1)
				{
					i = -1;
					while (++i < lem->size)
						if (lem->smezh[i][j] && find_room_ind(i, lem)->out > 1)
							lem->smezh[i][j] = 0;
				}
			}
	}
}
