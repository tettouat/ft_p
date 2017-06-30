/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:35:17 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 17:45:09 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "stream.h"
#include "server.h"
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

int		handle_put(t_stream *stream, t_state *state)
{
	int		fd;
	char	*line;
	size_t	linesize;

	(void)state;
	if (!read_string(stream, &line, NULL))
		return (0);
	if (ft_strchr(line, '/') != NULL
		|| (fd = open(line, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) < 0)
	{
		write_s8(stream, 0);
		write_string(stream, "Permission denied", 17);
		return (1);
	}
	write_s8(stream, 1);
	while (read_string(stream, &line, &linesize) && linesize > 0)
	{
		if (write(fd, line, linesize) < 0)
			return (0);
	}
	return (1);
}
