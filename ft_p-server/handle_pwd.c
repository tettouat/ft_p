/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:35:24 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 17:45:14 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include "../libft/libft.h"

int		handle_pwd(t_stream *stream, t_state *state)
{
	char	cwd[MAXPATHLEN];

	(void)state;
	if (getcwd(cwd, MAXPATHLEN) == NULL)
		return (0);
	write_string(stream, cwd, ft_strlen(cwd));
	return (1);
}
