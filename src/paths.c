/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:44:23 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/30 21:31:59 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Debug print
*/

void	print_paths(int **paths, t_lemin *lem);

/*
**	A good (?) pathfinder
*/

int		pathscnt(t_lemin *lem)
{
	int		i;
	int		cnt;

	cnt = 0;
	i = -1;
	while (++i < lem->size)
		if (lem->smezh[lem->start->index][i])
			cnt++;
	return (cnt);
}

int		*follow_path(t_lemin *lem, int i)
{
	int		j;
	int		p;
	int		*path;

	path = (int *)malloc(sizeof(int) * (pathlen(lem, i) + 1));
	j = -1;
	p = 0;
	while (++j < lem->size && i != lem->end->index)
	{
		if (lem->smezh[i][j])
		{
			path[p] = j;
			p++;
			i = j;
			j = -1;
		}
	}
	path[p] = -1;
	return (path);
}

void	create_paths(t_lemin *lem)
{
	int		i;
	int		p;
	int		start;
	int		**paths;

	start = lem->start->index;
	paths = (int**)malloc(sizeof(int *) * pathscnt(lem));
	i = -1;
	p = 0;
	while (++i < lem->size)
	{
		if (lem->smezh[start][i])
		{
			paths[p] = follow_path(lem, i);
			p++;
		}
	}
	print_paths(paths, lem);
}

/*
**	Debug print
*/

void	print_paths(int **paths, t_lemin *lem)
{
	int		i;
	int		j;

	i = -1;
	while (++i < pathscnt(lem, lem->start->index))
	{
		j = -1;
		while (paths[i][++j] != -1)
		{
			printf("%s ", find_room_ind(paths[i][j], lem)->name);
		}
		printf("\n");
	}
}

void	create_tacts()