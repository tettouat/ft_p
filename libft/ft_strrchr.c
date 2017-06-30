/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:39:58 by tettouat          #+#    #+#             */
/*   Updated: 2014/04/13 17:39:58 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*chr;

	chr = NULL;
	if (*s == (char)c)
		chr = (char *)s;
	while (*s)
	{
		if (*s == c)
			chr = (char *)s;
		s++;
	}
	if (c == '\0')
		chr = (char *)s;
	return (chr);
}
