/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:18:04 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/09 16:26:45 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_ants(char *line)
{
	
}

void	read_rooms(char *line)
{
	
}

void	read_links(char *line)
{
	
}

/*
**	part = 0; -> read number of ants
**	part = 1; -> read the rooms
**	part = 2; -> read the links
*/

t_lemin		*parse_input(void)
{
	char	*line;
	int		stat;
	int		part;
	int		se;
	t_lemin	*lem;

	se = 0;
	part = 0;
	if (!(lem = (t_lemin *)malloc(sizeof(t_lemin))))
		return (NULL);
	while ((stat = ft_gnl(0, &line)) > 0)
	{
		if (line[0] == "#")
		{
			
		}
		if (part == 0)
			read_ants(line);
		else if (part == 1)
			read_rooms(line);
		else if (part == 3)
			read_links(line);
		ft_strdel(&line);
	}
}
