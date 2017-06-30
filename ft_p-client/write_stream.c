/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stream.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:32:24 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 17:46:43 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <netinet/in.h>
#include "stream.h"

int				write_s8(t_stream *stream, int8_t c)
{
	return (write(stream->fd, &c, 1) >= 0);
}

int				write_s32be(t_stream *stream, int32_t nbr)
{
	nbr = htonl(nbr);
	return (write(stream->fd, &nbr, sizeof(nbr)) >= 0);
}

int				write_string(t_stream *stream, char *s, size_t len)
{
	if (s == NULL)
	{
		s = "";
		len = 0;
	}
	return (write_s32be(stream, len) && write(stream->fd, s, len) >= 0);
}
