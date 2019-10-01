/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:38:31 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/01 20:17:53 by cpollich         ###   ########.fr       */
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
		{
			lem->smezh[index][i] = 0;
			find_room_ind(index, lem)->out -= 1;
		}
	}
}

void		remove_output_forks(t_lemin *lem)
{
	int		lvl;
	t_rooms	*rooms;
	t_rooms	*tmp;

	if (!(tmp = find_final_room(lem)))
		return ;
	lvl = find_final_room(lem)->room->level + 1;
	while (--lvl > 0)
	{
		rooms = lem->list;
		while ((rooms = is_same_lvl(lvl, rooms)))
		{
			clean_outs(lem, rooms->room->index);
			rooms = rooms->next;
		}
	}
}

void		remove_input_forks(t_lemin *lem)
{
	t_rooms	*rooms;
	int		i;
	int		cl;
	t_rooms	*tmp;
	t_room	*room;

	cl = 0;
	while ((tmp = find_final_room(lem)) && ++cl <= tmp->room->level
		&& (rooms = lem->list))
		while (rooms)
		{
			if (rooms->room->level == cl && rooms->room->in > 1)
			{
				room = rooms->room;
				i = -1;
				while (++i < lem->size)
					if (lem->smezh[i][room->index] &&
							find_room_ind(i, lem)->out > 1 && room->in > 1)
					{
						lem->smezh[i][room->index] = 0;
						rooms->room->in -= 1;
					}
			}
			rooms = rooms->next;
		}
}

void		remove_input_forks_dumb(t_lemin *lem)
{
	t_rooms	*rooms;
	int		ri;
	int		i;
	int		cl;
	t_rooms	*tmp;

	cl = 0;
	while ((tmp = find_final_room(lem)) && ++cl <= tmp->room->level
			&& (rooms = lem->list))
		while (rooms)
		{
			if (rooms->room->level == cl && rooms->room->in > 1)
			{
				ri = rooms->room->index;
				i = -1;
				while (++i < lem->size)
					if (lem->smezh[i][ri] && rooms->room->in > 1)
					{
						remove_from_smezh(find_room_ind(i, lem), lem);
						rooms->room->in -= 1;
					}
			}
			rooms = rooms->next;
		}
}
