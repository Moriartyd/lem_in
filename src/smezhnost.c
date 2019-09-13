/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smezhnost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:01:04 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/13 18:32:30 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	**create_smezh(t_lemin *lem)
{
	int	i;
	int	j;
	int	**arr;

	if (!(arr = (int **)malloc(sizeof(int *) * lem->size)))
		return (0);
	i = 0;
	while (i < lem->size)
		arr[i++] = (int *)malloc(sizeof(int) * lem->size);
	i = 0;
	while (i < lem->size)
	{
		j = 0;
		while (j < lem->size)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (arr);
}

/*
**	Дополнение таблицы смежности
*/

void	add_smezh(char *name1, char *name2, t_lemin *lem)
{
	int	**arr;
	int	ind1;
	int	ind2;

	arr = lem->smezh;
	ind1 = find_room(name1, lem)->room->index;
	ind2 = find_room(name2, lem)->room->index;
	arr[ind1][ind2] = 1;
	arr[ind2][ind1] = 1;
}

void	parse_link(char *str, t_lemin *lem, int *stat)
{

	char	**arr;

	sort_nodes(lem->list);
	if (!(arr = ft_strsplit(str, '-')))
		*stat = -1;
	if (!lem->smezh)
		lem->smezh = create_smezh(lem);
	if (!lem->smezh)
		*stat = -1;
	add_smezh(arr[0], arr[1], lem);
	*stat = 3;
}
