/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:42:08 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 17:46:15 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include "stream.h"
#include "protocol.h"

int		handle_ls(t_stream *stream, char *line, char **cmd)
{
	char	*lsres;

	(void)cmd;
	write_s8(stream, LS);
	write_string(stream, line, ft_strlen(line));
	if (!read_until(stream, &lsres, '\0'))
		return (0);
	ft_putendl("SUCCESS");
	ft_putstr(lsres);
	return (1);
}
