/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:34:41 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 18:17:43 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "protocol.h"

int		handle_fail(t_stream *stream, t_state *state)
{
	send_failure(stream, NULL);
	state->running = 0;
	return (0);
}

void	handle_cmd(int cmd, t_stream *stream, t_state *state)
{
	static t_handler	handlers[27];
	int					i;

	if (handlers[26] == NULL)
	{
		i = 0;
		while (i < 27)
			handlers[i++] = handle_fail;
		handlers[CD - 'A'] = handle_cd;
		handlers[LS - 'A'] = handle_ls;
		handlers[GET - 'A'] = handle_get;
		handlers[PUT - 'A'] = handle_put;
		handlers[PWD - 'A'] = handle_pwd;
		handlers[QUIT - 'A'] = handle_quit;
	}
	handlers[cmd - 'A'](stream, state);
}
