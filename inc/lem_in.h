/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:44:25 by cpollich          #+#    #+#             */
/*   Updated: 2019/10/01 15:40:24 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

# include "libft.h"
# include "ft_printf.h"

/*
**	Структура для комнаты
*/

typedef struct		s_room
{
	char			*name;
	int				index;
	int				level;
	int				x;
	int				y;
	int				in;
	int				out;
}					t_room;

/*
**	Структура для списка комнат
*/

typedef struct		s_rooms
{
	t_room			*room;
	struct s_rooms	*next;
	struct s_rooms	*prev;
}					t_rooms;

/*
**	Главная структура где хранятся комнаты, связи и муравьи
*/

typedef struct		s_lemin
{
	int				ants;
	t_room			*start;
	t_rooms			*list;
	t_room			*end;
	int				size;
	int				**smezh;
}					t_lemin;

/*
**	Очередь комнат для обхода графа
*/

typedef struct		s_queue
{
	int				index;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_ant
{
	int				path;
	int				room;
}					t_ant;

/*
**	DEBUG	DELETE 	IT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
void				print_nodes(t_rooms *head);

/*
**	Rooms memory
*/
t_rooms				*add_rooms(t_rooms *src, t_room *room);
t_rooms				*init_rooms(void);
t_rooms				*create_firstrooms(t_room *room);
t_rooms				*rm_rooms(t_rooms *head);

/*
**	Room memory
*/
t_room				*create_room(size_t size, int *ind);
t_room				*rm_room(t_room *room);
int					valid_room(t_room *room1, t_room *room2);

/*
**	Parsing
*/
int					parse_input(t_lemin *lem, char *name);
int					what_parse(char *line, t_lemin *lem,
						int *p, char **addline);
int					**create_smezh(t_lemin *lem);
void				set_coord(t_room *room, char *line);
void				parse_link(char *str, t_lemin *lem, int *stat);

/*
**	Searching
*/
t_rooms				*find_room(const char *name, t_lemin *lem);
t_room				*find_room_ind(int ind, t_lemin *lem);
t_rooms				*find_final_room(t_lemin *lem);

/*
**	Errors
*/
void				error_manager(t_lemin *lem, int error);
int					check_startend(t_lemin *lem);
int					check_lem(t_lemin *lem);

/*
**	Remove forks
*/
void				remove_input_forks(t_lemin *lem);
void				remove_input_forks_dumb(t_lemin *lem);
void				remove_output_forks(t_lemin *lem);
int					remove_from_smezh(t_room *room, t_lemin *lem);

/*
**	Queue
*/
void				push_queue(t_queue **queue, int index);
int					pop_queue(t_queue **queue);

/*
**	Solver
*/
t_rooms				*is_same_lvl(int lvl, t_rooms *head);
void				bfs(t_lemin *lem);
void				create_paths(t_lemin *lem);
void				sort_array(int **arr, int len);
int					pathlen(t_lemin *lem, int index);
int					pathscnt(t_lemin *lem);
int					*weigh_paths(int **paths, t_lemin *lem);
void				move_ants(int **paths, int *weights, t_lemin *lem);

/*
**	Ants memory
*/
t_ant				*create_ants(t_lemin *lem);
t_ant   			*remove_ants(t_ant **ant);

/*
**	Weights memory
*/
int					*init_weights(int cnt);
int					*remove_weights(int **w);


/*
**	Other
*/
void				mem_clean(t_lemin *lem);

#endif
