/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:02:33 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/09 23:13:29 by cpollich         ###   ########.fr       */
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

	left = head;
	right = head->next;
	while (left->next)
	{
		while (right)
		{
			if (ft_strcmp(left->room->name, right->room->name) < 0)
			{
				tmp = left->room;
				left->room = right->room;
				right->room = tmp;
			}
			right = right->next;
		}
		left = left->next;
		right = right->next;
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

