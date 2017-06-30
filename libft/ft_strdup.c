/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/13 17:36:45 by tettouat          #+#    #+#             */
/*   Updated: 2014/04/13 17:36:46 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*scpy;

	len = ft_strlen(s1) + 1;
	if ((scpy = (char *)malloc(len)) == NULL)
		return (NULL);
	ft_memcpy(scpy, s1, len);
	return (scpy);
}
