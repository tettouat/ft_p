/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:35:32 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 17:45:18 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "protocol.h"
#include "../libft/libft.h"

static void	send_success(t_stream *stream, char *msg)
{
	if (!write_s8(stream, ACK))
		ft_putendl("ERR");
	if (!write_string(stream, msg, ft_strlen(msg)))
		ft_putendl("ERR");
}

int			handle_quit(t_stream *stream, t_state *state)
{
	send_success(stream, "Bye");
	state->running = 0;
	return (1);
}
