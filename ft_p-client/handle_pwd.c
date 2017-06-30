/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:42:16 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/08 16:30:51 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "protocol.h"
#include "stream.h"

int		handle_pwd(t_stream *stream, char *line, char **cmd)
{
	char	*res;

	(void)line;
	(void)cmd;
	write_s8(stream, PWD);
	if (!read_string(stream, &res, NULL))
		return (0);
	ft_putendl("SUCCESS");
	ft_putendl(res);
	return (1);
}
