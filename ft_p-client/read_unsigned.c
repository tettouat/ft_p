/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:32:14 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 17:46:36 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stream.h"
#include <arpa/inet.h>

int				read_u8(t_stream *stream, uint8_t *c)
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

int				read_u32be(t_stream *stream, uint32_t *nbr)
{
	uint8_t	*ptr;
	int		res;

	ptr = (uint8_t*)nbr;
	res = read_u8(stream, ptr + 0)
			&& read_u8(stream, ptr + 1)
			&& read_u8(stream, ptr + 2)
			&& read_u8(stream, ptr + 3);
	if (res)
		*nbr = ntohl(*nbr);
	return (res);
}
