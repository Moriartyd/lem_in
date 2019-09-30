/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:38:31 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/30 15:37:06 by adavis           ###   ########.fr       */
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
	t_rooms	*rooms;
	int		ri;
	int		i;
	int		cl;

	cl = 0;
	while (++cl <= find_final_room(lem)->room->level)
	{
		rooms = lem->list;
		while (rooms)
		{
			if (rooms->room->level == cl && rooms->room->in > 1)
			{
				ri = rooms->room->index;
				i = -1;
				while (++i < lem->size)
				{
					if (lem->smezh[i][ri] && find_room_ind(i, lem)->out > 1)
					{
						lem->smezh[i][ri] = 0;
						rooms->room->in -= 1;
					}
				}
			}
			rooms = rooms->next;
		}
	}
}

void	remove_input_forks_dumb(t_lemin *lem)
{
	t_rooms	*rooms;
	int		ri;
	int		i;
	int		cl;

	cl = 0;
	while (++cl <= find_final_room(lem)->room->level)
	{
		rooms = lem->list;
		while (rooms)
		{
			if (rooms->room->level == cl && rooms->room->in > 1)
			{
				ri = rooms->room->index;
				i = -1;
				while (++i < lem->size)
				{
					if (lem->smezh[i][ri] && rooms->room->in > 1)
					{
						printf(">%d\n", rooms->room->in);
						remove_from_smezh(find_room_ind(i, lem), lem);
						rooms->room->in -= 1;
					}
				}
			}
			rooms = rooms->next;
		}
	}
}
