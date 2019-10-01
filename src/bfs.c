/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:15:40 by adavis            #+#    #+#             */
/*   Updated: 2019/10/01 18:45:16 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

/*
**	DEBUG PRINT
*/

// void		print_levels(t_lemin *lem)
// {
// 	while (lem->list)
// 	{
// 		printf("%s\t%d\n", lem->list->room->name, lem->list->room->level);
// 		lem->list = lem->list->next;
// 	}
// }

void		print_smezh(t_lemin *lem)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < lem->size * 2 + 16)
		printf("-");
	printf("\n");
	i = 0;
	while (i < lem->size)
	{
		printf("%16s\t", find_room_ind(i, lem)->name);
		j = 0;
		while (j < lem->size)
		{
			printf("%d ", lem->smezh[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int			remove_from_smezh(t_room *room, t_lemin *lem)
{
	int		i;

	i = 0;
	while (i < lem->size)
	{
		if (lem->smezh[i][room->index] == 1)
		{
			lem->smezh[i][room->index] = 0;
			find_room_ind(i, lem)->out -= 1;
			return (0);
		}
		i++;
	}
	return (1);
}

static void	remove_deadends(t_lemin *lem)
{
	t_room	*room;
	int		all_clear;
	int		i;
	int		j;

	all_clear = 0;
	while (!all_clear)
	{
		all_clear = 1;
		i = -1;
		while (++i < lem->size)
		{
			j = -1;
			while (++j < lem->size)
				if (lem->smezh[i][j])
					if ((room = find_room_ind(j, lem)) &&
						room->out == 0 && room->level != INT_MAX)
						all_clear = remove_from_smezh(room, lem);
		}
	}
}

/*
**	OUT	- horizontal
**	IN	- vertical
*/

static void	count_in_out(t_lemin *lem)
{
	int		index;
	int		i;
	t_rooms	*rooms;

	rooms = lem->list;
	while (rooms && rooms->room)
	{
		index = rooms->room->index;
		i = -1;
		while (++i < lem->size)
		{
			rooms->room->out += lem->smezh[index][i];
			rooms->room->in += lem->smezh[i][index];
		}
		rooms = rooms->next;
	}
	remove_deadends(lem);
	remove_input_forks(lem);
	remove_input_forks_dumb(lem);
	remove_deadends(lem);
	remove_output_forks(lem);
	create_paths(lem);
}

static void	remove_links(t_lemin *lem)
{
	int		i;
	int		j;
	t_room	*k;
	t_room	*l;

	i = -1;
	while (++i < lem->size)
	{
		j = -1;
		while (++j < lem->size)
		{
			if (lem->smezh[i][j])
			{
				k = find_room_ind(i, lem);
				l = find_room_ind(j, lem);
				if (k->level < 0 || k->level >= l->level || l->level < 0)
					lem->smezh[i][j] = 0;
			}
		}
	}
	count_in_out(lem);
}

void		bfs(t_lemin *lem)
{
	t_queue	*q;
	int		i;
	int		current;

	q = NULL;
	push_queue(&q, lem->start->index);
	while (q)
	{
		current = pop_queue(&q);
		i = 0;
		while (i < lem->size)
		{
			if (lem->smezh[current][i] && find_room_ind(i, lem)->level == -1)
			{
				push_queue(&q, i);
				if (find_room_ind(i, lem)->level == -1)
					find_room_ind(i, lem)->level =
						find_room_ind(current, lem)->level + 1;
			}
			i++;
		}
	}
	remove_links(lem);
}
