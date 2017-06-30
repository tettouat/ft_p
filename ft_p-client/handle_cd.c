/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:41:58 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 17:46:10 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "stream.h"
#include "protocol.h"

int			read_result(t_stream *stream)
{
	int8_t	cmd;
	char	*reason;

	if (!read_s8(stream, &cmd))
		return (0);
	if (cmd == ACK || cmd == ERR)
	{
		ft_putstr(cmd == ACK ? "SUCCESS:" : "ERROR:");
		if (!read_string(stream, &reason, NULL))
			return (0);
		else
			ft_putendl(reason);
	}
	else
		return (0);
	return (1);
}

int			handle_cd(t_stream *stream, char *line, char **cmd)
{
	(void)line;
	if (cmd[1] == NULL)
	{
		ft_putendl("Usage: cd <path>");
		return (1);
	}
	if (!write_s8(stream, CD)
			|| !write_string(stream, cmd[1], ft_strlen(cmd[1])))
		return (0);
	return (read_result(stream));
}
