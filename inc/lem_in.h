/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:44:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/11 20:03:42 by cpollich         ###   ########.fr       */
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
	int				index;
	t_list			*link;
}					t_room;

typedef struct		s_rooms
{
	t_room			*room;
	struct s_rooms	*next;
	struct s_rooms	*prev;
}					t_rooms;

typedef struct		s_lemin
{
	unsigned		ants;
	t_room			*start;
	t_rooms			*list;
	t_room			*end;
	size_t			size;
}					t_lemin;

int					parse_input(t_lemin *lem, char *name);
void				sort_nodes(t_rooms *head);
void				print_nodes(t_rooms *head);
t_rooms				*add_rooms(t_rooms *src, t_room *room);
t_rooms				*init_rooms(void);
t_room				*create_room(size_t size, int ind);
#endif
