/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:02:33 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/10 21:37:32 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void		sort_nodes(t_rooms *head)
{
	t_rooms *left;
	t_room	*tmp;
	t_rooms	*right;
	size_t	size;
	int		res;

	left = head;
	right = head->next;
	while (left->next)
	{
		while (right)
		{
			if ((res = ft_strcmp(left->room->name, right->room->name)) > 0)
			{
				tmp = left->room;
				left->room = right->room;
				right->room = tmp;
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
}

void		print_nodes(t_rooms *head)
{
	while (head)
	{
		printf("%s\n", head->room->name);
		head = head->next;
	}
}

t_rooms	*find_room(const char *str, t_rooms *lst)
{
	
}
