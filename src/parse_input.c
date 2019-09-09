/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:18:04 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/09 20:59:16 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*parse_room(char *line, t_lemin *lem, int *status)
{
	t_room	*room;
	size_t	size;

	size = ft_strchr(line, ' ') - line;
	if (!(room = create_room(size)))
		return (NULL);
	ft_strncpy(room->name, line, size);
	if (!(lem->list = add_rooms(lem->list, room)))
		return (NULL);
	*status = 2;
	return (room);
}

static void		parse_ants(char *line, t_lemin *lem, int *status)
{
	lem->ants = ft_atoi(line);
	*status = 2;
}

static int		parse_command(t_lemin *lem, int status, int fd)
{
	char	*line;
	int		s;
	t_room	*room;
	int		ret;

	ret = 3;
	if (ft_get_next_line(fd, &line) < 0)
		return (-ft_strdel(&line));
	s = get_type(line);
	if (s != 4)
		return (-ft_strdel(&line));
	if (s == 4)
	{
		if (status == 1 && !lem->start)
			if (!(lem->start = parse_room(line, lem, &ret)))
				return (-ft_strdel(&line));
		if (status == 2 && !lem->end)
			if (!(lem->end = parse_room(line, lem, &ret)))
				return (-ft_strdel(&line));
		// if ((status == 1 && !lem->start) || (status == 2 && !lem->end))
			// ret = 0;
	}
	return (-ft_strdel(&line) + ret);
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

int				parse_input(t_lemin *lem, char *name)
{
	char	*line;
	int		p[3];
	t_rooms	*r;

	if (!lem || (p[0] = !name ? 0 : open(name, O_RDONLY)) < 0)
		return (-1);
	p[2] = 0;
	p[1] = 0;
	while (ft_get_next_line(p[0], &line) > 0 && p[1] >= 0)
	{
		p[1] = get_type(line);
		if (p[1] == -1 || ((p[2] == 1 || p[2] == 2) && p[1] != 4)
			|| (p[2] == 3 && p[1] == 4))
			return (-ft_strdel(line));
		if (p[1] == 1 || p[1] == 2)
			p[2] = parse_command(lem, p[1], p[0]);
		else if (p[1] == 4 || p[1] == 5)
			p[1] == 5 ? parse_ant(lem, line, &p[2])
			: parse_room(line, lem, &p[2]);
		p[1] == link ? parse_link : (0);
		ft_strdel(&line);
	}
	close(p[0]);
}
