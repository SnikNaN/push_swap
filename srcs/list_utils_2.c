/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:47:17 by eshana            #+#    #+#             */
/*   Updated: 2021/12/08 21:29:36 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_list_size(t_list *a)
{
	t_list			*lst;
	unsigned int	size;

	lst = a;
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
		if (lst == a)
			break ;
	}
	return (size);
}

unsigned int	ft_elem_height(t_list *begin, t_list *elem)
{
	unsigned int	height;

	height = 0;
	while (begin != elem)
	{
		begin = begin->next;
		height++;
	}
	return (height);
}

t_list	*ft_find_place(t_list *a, t_list *elem)
{
	while (!(
			(a->num < ft_lstlast(a)->num
				&& (elem->num > ft_lstlast(a)->num || elem->num < a->num)
			)
			|| (a->num > elem->num && ft_lstlast(a)->num < elem->num)
		))
		a = a->next;
	return (a);
}

void	ft_find_min_max(t_list *lst, t_params *params)
{
	t_list	*begin_list;

	params->min = lst->index;
	params->max = lst->index;
	begin_list = lst;
	while (lst)
	{
		if (lst->index < params->min)
			params->min = lst->index;
		if (lst->index > params->max)
			params->max = lst->index;
		lst = lst->next;
		if (lst == begin_list)
			return ;
	}
}
