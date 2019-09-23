/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:44:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/23 19:22:19 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <errno.h>

# include "../libft/inc/libft.h"

typedef struct		s_room
{
	char			*name;
	int				index;
	int				visit;
	int				level;
	// t_list			*link;
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
	int				size;
	int				**smezh;
}					t_lemin;

int					parse_input(t_lemin *lem, char *name);
int					what_parse(char *line, t_lemin *lem, int *p, char *addline);
// int					get_type(char *str);
void				sort_nodes(t_rooms *head);
void				print_nodes(t_rooms *head);
t_rooms				*add_rooms(t_rooms *src, t_room *room);
t_rooms				*init_rooms(void);
t_rooms				*create_firstrooms(t_room *room);
t_room				*create_room(size_t size, int *ind);
t_rooms				*find_room(const char *name, t_lemin *lem);
void				parse_link(char *str, t_lemin *lem, int *stat);
t_room	*rm_room(t_room *room);
t_rooms	*rm_rooms(t_rooms *head);
void	mem_clean(t_lemin *lem);
#endif
