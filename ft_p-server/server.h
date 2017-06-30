/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:33:18 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 18:10:34 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <sys/param.h>
# include "stream.h"

typedef struct	s_state
{
	int			id;
	int			running;
	char		rootdir[MAXPATHLEN];
}				t_state;

typedef int		(*t_handler)(t_stream *, t_state *);
void			send_failure(t_stream *stream, char *msg);
int				handle_cd(t_stream *stream, t_state *state);
int				handle_put(t_stream *stream, t_state *state);
int				handle_get(t_stream *stream, t_state *state);
int				handle_ls(t_stream *stream, t_state *state);
int				handle_pwd(t_stream *stream, t_state *state);
int				handle_quit(t_stream *stream, t_state *state);
int				handle_fail(t_stream *stream, t_state *state);
void			handle_cmd(int cmd, t_stream *stream, t_state *state);
void			display_port(int i);
#endif
