/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:15:40 by adavis            #+#    #+#             */
/*   Updated: 2019/09/26 20:41:18 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		q_len(t_queue *q)
{
	int		cnt;

	cnt = 0;
	while (q)
	{
		cnt++;
		q = q->next;
	}
	return (cnt);
}

void	print_levels(t_lemin *lem)
{
	while (lem->list)
	{
		printf("%s\t%d\n", lem->list->room->name, lem->list->room->level);
		lem->list = lem->list->next;
	}
}

/*
**	DEBUG PRINT
*/

void	print_smezh(t_lemin *lem)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < lem->size * 2 + 7)
		printf("-");
	printf("\n");
	i = 0;
	while (i < lem->size)
	{
		printf("%s\t", find_room_ind(i, lem)->name);
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

/*
**	Shitty pathfinder
*/

void	make_path(t_lemin *lem, t_stack **s)
{
	int		i;
	int		current;

	current = read_stack(*s);
	if (current != lem->end->index)
	{
		i = 0;
		while (i < lem->size)
		{
			if (lem->smezh[current][i] == 1)
			{
				push_stack(s, i);
				make_path(lem, s);
			}
			i++;
		}
	}
	else
	{
		push_stack(s, -1);
	}
}

/*
**	Shitty pathfinder
*/

void	create_paths(t_lemin *lem)
{
	t_stack	*s;
	int		i;

	s = NULL;
	push_stack(&s, lem->start->index);
	make_path(lem, &s);
	pop_stack(&s);
	while (s)
	{
		if (read_stack(s) != lem->start->index)
		{
			i = pop_stack(&s);
			if (i == -1)
				printf("\n");
			else
				printf("%s ", find_room_ind(i, lem)->name);
		}
		else
			pop_stack(&s);
	}
}

int		min_link(t_lemin *lem, int index)
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

void	clean_outs(t_lemin *lem, int index)
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

void	remove_output_forks(t_lemin *lem)
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

void	remove_input_forks(t_lemin *lem)
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
		{
			if (find_room_ind(j, lem)->level == current_level)
			{
				flag = 1;
				if (find_room_ind(j, lem)->in > 1)
				{
					i = -1;
					while (++i < lem->size)
						if (lem->smezh[i][j] == 1 &&
								find_room_ind(i, lem)->out > 1)
							lem->smezh[i][j] = 0;
				}
			}
		}
	}
}

int		remove_from_smezh(t_room *room, t_lemin *lem)
{
	int		i;
	int		j;

	i = 0;
	while (i < lem->size)
	{
		j = 0;
		while (j < lem->size)
		{
			if (j == room->index && lem->smezh[i][j] == 1)
			{
				lem->smezh[i][j] = 0;
				find_room_ind(i, lem)->out -= 1;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	remove_deadends(t_lemin *lem)
{
	t_rooms *rooms;
	int		all_clear;
	int		i;
	int		j;

	all_clear = 0;
	while (!all_clear)
	{
		all_clear = 1;
		rooms = lem->list;
		while (rooms)
		{
			if (rooms->room->out == 0 && rooms->room->level != INT_MAX)
				all_clear = remove_from_smezh(rooms->room, lem);
			rooms = rooms->next;
		}
	}
	print_smezh(lem);
	remove_input_forks(lem);
	print_smezh(lem);
	remove_output_forks(lem);
	print_smezh(lem);
	create_paths(lem);
}

/*
**	OUT	- horizontal
**	IN	- vertical
*/

void	count_in_out(t_lemin *lem)
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
}

void	remove_links(t_lemin *lem)
{
	int		i;
	int		j;
	t_room	*k;
	t_room	*l;

	i = 0;
	while (i < lem->size)
	{
		printf("%s\t", find_room_ind(i, lem)->name);
		j = 0;
		while (j < lem->size)
		{
			k = find_room_ind(i, lem);
			l = find_room_ind(j, lem);
			if (k->level >= l->level || k->level < 0 || l->level < 0)
				lem->smezh[i][j] = 0;
			printf("%d ", lem->smezh[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	count_in_out(lem);
}

void	bfs(t_lemin *lem)
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
