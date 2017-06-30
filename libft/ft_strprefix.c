/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 14:39:20 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/02 14:40:00 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strprefix(const char *str, const char *prefix)
{
	while (*prefix != '\0' && *str != '\0' && *str == *prefix)
	{
		prefix++;
		str++;
	}
	return (*prefix == '\0');
}
