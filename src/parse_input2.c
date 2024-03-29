/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:27:54 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/01 21:38:05 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	set_startend(t_lemin *lem)
{
	if (lem->start)
		lem->start->level = 0;
	if (lem->end)
		lem->end->level = INT_MAX;
	return (0);
}

int			isint(char *str)
{
	int		neg;
	char	*s;

	neg = 0;
	if (*str == '-' || *str == '+')
	{
		str++;
		neg = 1;
	}
	else if (*str == '+')
		str++;
	else if (!ft_isdigit(*str))
		return (0);
	s = str;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	if ((!neg && ft_strlen(str) == 10 && ft_strcmp(str, "2147483647") > 0) ||
		(neg && ft_strlen(str) == 10 && ft_strcmp(str, "2147483648") > 0) ||
		(ft_strlen(str) > 10))
		return (0);
	return (1);
}

/*
**	1	- start
** 	2	- end
** 	3	- link
**	4	- room
**	5	- ants
**	-1	- error
**	-2	- error with lem
**	-3	- error with links
**	-4	- error with room
**	-6	- error with coords
**	0	- comment
*/

int			parse_input(t_lemin *lem, char *n)
{
	char	*line;
	char	*output;
	int		p[4];
	int		ret;
	char	buff[1];

	if (!lem || (p[0] = !n ? 0 : open(n, O_RDONLY)) < 0 || read(p[0], buff, 0))
		return (-1);
	output = ft_strnew(0);
	p[2] = 0;
	p[1] = 0;
	p[3] = 0;
	while (ft_gnl(p[0], &line) > 0 && p[1] >= 0)
	{
		ret = what_parse(line, lem, p, &output);
		if (ret < 0)
			return (ret - ft_strdel(&output) + 1);
	}
	close(p[0]);
	if (check_lem(lem) != 0)
		return (check_lem(lem));
	ft_putstr(output);
	set_startend(lem);
	ft_strdel(&output);
	return (0);
}
