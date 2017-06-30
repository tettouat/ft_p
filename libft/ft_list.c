/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 17:26:02 by tettouat          #+#    #+#             */
/*   Updated: 2015/01/20 16:44:35 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst			*ft_creat_list(void)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	new->next = new;
	new->start = new;
	new->str = ft_strdup("");
	return (new);
}

t_lst			*ft_add_lst(t_lst *lst, char *str)
{
	t_lst	*new;

	if (ft_strcmp(lst->str, "") == 0)
		new = lst;
	else
	{
		new = malloc(sizeof(t_lst));
		new->next = lst->start;
		new->start = lst->start;
		lst->next = new;
	}
	new->str = ft_strdup(str);
	return (new);
}

void			ft_free_lst(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	lst = lst->start;
	while (lst->next != lst->start)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

t_lst			*ft_find_like(t_lst *lst, char *str)
{
	t_lst	*tmp;
	int		size;

	tmp = lst;
	size = ft_strlen(str);
	lst = lst->next;
	while (tmp != lst)
	{
		ft_putstr(lst->str);
		if (ft_strncmp(str, lst->str, size) == 0)
			return (lst);
		lst = lst->next;
	}
	if (ft_strncmp(str, lst->str, size) == 0)
		return (lst);
	return (tmp);
}
