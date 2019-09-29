/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:18:04 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/29 18:07:14 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		get_type(char *str)
{
	if (str[0] == '#' && str[1] == '#' && !ft_strcmp(str + 2, "start"))
		return (1);
	else if (str[0] == '#' && str[1] == '#' && !ft_strcmp(str + 2, "end"))
		return (2);
	else if (ft_strchr(str, '-') && str[0] != '#')
		return (3);
	else if (str[0] == '#')
		return (0);
	else if (ft_strnchr(str, ' ', 2) != -1 && str[0] != '#')
		return (4);
	else if (!ft_isnumeric(str))
		return (-1);
	else
		return (5);
}

static t_room	*parse_room(char *line, t_lemin *lem, int *status, int *ind)
{
	t_room	*room;
	size_t	size;
	t_rooms	*head;
	int		check;

	size = ft_strchr(line, ' ') - line;
	if (!(room = create_room(size, ind)))
		return (NULL);
	set_coord(room, line + size);
	ft_strncpy(room->name, line, size);
	if (!lem->list)
	{
		if (!(lem->list = create_firstrooms(room)))
			return (NULL);
		return (room);
	}
	head = lem->list;
	while (head->next)
	{
		check = valid_room(room, head->room);// && (check = valid_room(room, head->room)))
		head = head->next;
	}
	// check = valid_room(room, head->room);
	if (!(head->next = add_rooms(head, room)))
		return (NULL);
	*status = check ? 4 : -4;
	lem->size = *ind;
	return ((check) ? (room) : (NULL));
}

static void		parse_ants(char *line, t_lemin *lem, int *status)
{
	lem->ants = ft_atoi(line);
	*status = 4;
}

static int		parse_command(t_lemin *lem, int *p, char **addline)
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
		line = ft_strjoinch(&line, '\n');
		*addline = ft_stradd(*addline, line);
	}
	return (-ft_strdel(&line) + ret);
}

int				what_parse(char *line, t_lemin *lem, int *p, char **addline)
{
	p[1] = get_type(line);
	if (p[1] == -1 || ((p[2] == 1 || p[2] == 2) && p[1] != 4)
		|| (p[2] == 3 && p[1] == 4))
		return (-ft_strdel(&line) - 1);
	if (p[1] == 1 || p[1] == 2)
	{
		line = ft_strjoinch(&line, '\n');
		*addline = ft_stradd(*addline, line);
		p[2] = parse_command(lem, p, addline);
	}
	else if (p[1] == 4 || p[1] == 5)
		p[1] == 5 ? parse_ants(line, lem, &p[2]) :
		parse_room(line, lem, &p[2], &p[3]);
	p[1] == 3 ? parse_link(line, lem, &p[2]) : (0);
	if (p[1] != 1 && p[1] != 2)
	{
		line = ft_strjoinch(&line, '\n');
		*addline = ft_stradd(*addline, line);
	}
	ft_strdel(&line);
	return (p[2] < 0 ? (p[2]) : (0));
}
