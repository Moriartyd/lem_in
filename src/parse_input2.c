/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:27:54 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/24 17:13:42 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		set_startend(t_lemin *lem)
{
	if (lem->start)
		lem->start->level = 0;
	if (lem->end)
		lem->end->level = INT_MAX;
	return (0);
}

/*
**	1	- start
** 	2	- end
** 	3	- link
**	4	- room
**	5	- ants
**	-1	- error
**	0	- comment
*/

int				parse_input(t_lemin *lem, char *name)
{
	char	*line;
	char	*output;
	int		p[4];
	int		ret;

	if (!lem || (p[0] = !name ? 0 : open(name, O_RDONLY)) < 0)
		return (-1);
	p[2] = 0;
	p[1] = 0;
	p[3] = 0;
	output = "";
	while (ft_gnl(p[0], &line) > 0 && p[1] >= 0)
	{
		ret = what_parse(line, lem, p, &output);
		if (ret == -2)
			return (-2);
	}
	ft_strdel(&line);
	close(p[0]);
	if (check_lem(lem) == -2)
		return (-2);
	ft_putstr(output);
	set_startend(lem);
	ft_strdel(&output);
	return (0);
}
