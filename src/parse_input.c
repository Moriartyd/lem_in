/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:18:04 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/23 18:01:01 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		get_type(char *str)
{
	if (str[0] == '#' && str[1] == '#' && !ft_strcmp(str + 2, "start"))
		return (1);
	if (str[0] == '#' && str[1] == '#' && !ft_strcmp(str + 2, "end"))
		return (2);
	if (ft_strchr(str, '-'))
		return (3);
	if (ft_strnchr(str, ' ', 2) != -1)
		return (4);
	if (str[0] == '#')
		return (0);
	if (!ft_isnumeric(str))
		return (-1);
	return (5);
}

static t_room	*parse_room(char *line, t_lemin *lem, int *status, int *ind)
{
	t_room	*room;
	size_t	size;
	t_rooms	*head;

	size = ft_strchr(line, ' ') - line;
	if (!(room = create_room(size, ind)))
		return (NULL);
	ft_strncpy(room->name, line, size);
	if (!lem->list)
	{
		if (!(lem->list = create_firstrooms(room)))
			return (NULL);
		else
			return (room);
	}
	head = lem->list;
	while (head->next)
		head = head->next;
	if (!(head->next = add_rooms(head, room)))
		return (NULL);
	*status = 4;
	lem->size = *ind;
	return (room);
}

static void		parse_ants(char *line, t_lemin *lem, int *status)
{
	lem->ants = ft_atoi(line);
	*status = 4;
}

static int		parse_command(t_lemin *lem, int *p, char *addline) //int status, int fd, int *ind)
{
	char	*line;
	int		s;
	int		ret;

	ret = 5;
	if (ft_gnl(p[0], &line) < 0)
		return (-ft_strdel(&line));
	s = get_type(line);
	if (s != 4)
		return (-ft_strdel(&line));
	if (s == 4)
	{
		if (p[1] == 1 && !lem->start)
			if (!(lem->start = parse_room(line, lem, &ret, &p[3])))
				return (-ft_strdel(&line));
		if (p[1] == 2 && !lem->end)
			if (!(lem->end = parse_room(line, lem, &ret, &p[3])))
				return (-ft_strdel(&line));
		ret = 5;
		addline = ft_strjoin(addline, ft_strjoinch(&line, '\n'));
	}
	return (-ft_strdel(&line) + ret);
}

int	what_parse(char *line, t_lemin *lem, int *p, char *addline)
{
	p[1] = get_type(line);
	if (p[1] == -1 || ((p[2] == 1 || p[2] == 2) && p[1] != 4)
		|| (p[2] == 3 && p[1] == 4))
		return (-ft_strdel(&line));
	if (p[1] == 1 || p[1] == 2)
		p[2] = parse_command(lem, p, addline);
	else if (p[1] == 4 || p[1] == 5)
		p[1] == 5 ? parse_ants(line, lem, &p[2]) :
		parse_room(line, lem, &p[2], &p[3]);
	p[1] == 3 ? parse_link(line, lem, &p[2]) : (0);
	return (0);
}
