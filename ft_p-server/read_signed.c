/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:35:47 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 17:45:44 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stream.h"
#include <arpa/inet.h>

int				read_s8(t_stream *stream, int8_t *c)
{
	fill_buf(stream);
	if (stream->size <= 0)
		return (0);
	else
	{
		*c = stream->buf[stream->cursor++];
		return (1);
	}
}

int				read_s32be(t_stream *stream, int32_t *nbr)
{
	int8_t	*ptr;
	int		res;

	ptr = (int8_t*)nbr;
	res = read_s8(stream, ptr + 0)
			&& read_s8(stream, ptr + 1)
			&& read_s8(stream, ptr + 2)
			&& read_s8(stream, ptr + 3);
	if (res)
		*nbr = (int32_t)ntohl(*nbr);
	return (res);
}
