/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 13:25:43 by adavis            #+#    #+#             */
/*   Updated: 2019/10/01 15:43:18 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*create_ants(t_lemin *lem)
{
	t_ant	*ants;
	int		i;

	ants = (t_ant *)malloc(sizeof(t_ant) * lem->ants);
	i = -1;
	while (++i < lem->ants)
	{
		ants[i].room = lem->start->index;
		ants[i].path = -1;
	}
	return (ants);
}

int		ants_remaining(t_ant *ants, t_lemin *lem)
{
	int		i;
	int		cnt;

	cnt = 0;
	i = -1;
	while (++i < lem->ants)
		if (ants[i].room != lem->end->index)
			cnt++;
	return (cnt);
}

void	perform_move(t_ant *ants, int **paths, t_lemin *lem)
{
	int		i;
	int		j;

	i = -1;
	while (++i < lem->ants)
	{
		if (ants[i].path >= 0 && ants[i].room != lem->end->index)
		{
			j = 0;
			if (ants[i].room != lem->start->index)
				while (paths[ants[i].path][j++] != ants[i].room)
					;
			ants[i].room = paths[ants[i].path][j];
			ft_printf("L%d-%s", i + 1, find_room_ind(ants[i].room, lem)->name);
			if (ants[i + 1].path >= 0 && i + 1 < lem->ants)
				ft_printf(" ");
		}
	}
}

void	move_ants(int **paths, int *weights, t_lemin *lem)
{
	t_ant	*ants;
	int		i;
	int		j;

	if (paths == &weights)
		i = 0;
	ants = create_ants(lem);
	i = 0;
	printf("\n");
	while (ants_remaining(ants, lem))
	{
		j = -1;
		while (++j < pathscnt(lem) && i < lem->ants)
		{
			if (ants_remaining(ants, lem) > weights[j])
			{
				ants[i++].path = j;
			}
		}
		perform_move(ants, paths, lem);
		ft_printf("\n");
	}
}

int		*init_weights(int cnt)
{
	int		*weights;
	int		i;

	weights = (int *)malloc(sizeof(int) * cnt);
	i = -1;
	while (++i < cnt)
	{
		weights[i] = 0;
	}
	return (weights);
}

int		weigh_path(int **paths, t_lemin *lem, int ind, int len)
{
	int		i;
	int		weight;

	weight = 0;
	i = -1;
	while (++i < ind)
		weight += len - pathlen(lem, paths[i][0]);
	return (weight);
}

int		*weigh_paths(int **paths, t_lemin *lem)
{
	int		*weights;
	int		i;

	weights = init_weights(pathscnt(lem));
	i = -1;
	while (++i < pathscnt(lem))
		weights[i] = weigh_path(paths, lem,  i, pathlen(lem, paths[i][0]));
	return (weights);
}
