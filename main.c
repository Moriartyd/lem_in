/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 21:59:53 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/09 23:13:10 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_lemin		*lem;
	int			x;

	lem = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	parse_input(lem, argv[1]);
	while (lem->list->prev)
		lem->list = lem->list->prev;
	print_nodes(lem->list);
	sort_nodes(lem->list);
	printf("\nSORTED:\n");
	print_nodes(lem->list);
	return (0);
}