/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:44:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/09 20:20:14 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"

typedef struct		s_room
{
	char			*name;
	t_list			*link;
}					t_room;

typedef struct		s_lemin
{
	unsigned		ants;
	t_room			*start;
	t_rooms			*list;
	t_room			*end;
}					t_lemin;

typedef struct		s_rooms
{
	t_room			*room;
	struct s_rooms	*next;
	struct s_rooms	*prev;
}					t_rooms;

int				parse_input(t_lemin *lem, char *name);

#endif
