/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supporting_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:37:25 by eshana            #+#    #+#             */
/*   Updated: 2021/11/28 19:10:57 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list 	*ft_copy_lst(t_list *lst)
{
	t_list			*new_lst;
	t_list			*tmp;
	t_list			*begin_list;
	unsigned int	index;

	new_lst = NULL;
	index = 0;
	begin_list = lst;
	while (lst)
	{
		tmp = ft_lstnew(lst->num);
		if (!tmp)
		{
			ft_lstclear(&new_lst);
			return (NULL);
		}
		tmp->index = index++;
		ft_lstadd_back(&new_lst, tmp);
		lst = lst->next;
		if (lst == begin_list)
			break ;
	}
	return (new_lst);
}

static void	ft_set_index(t_list *a, t_list *sorted)
{
	t_list	*lst;
	t_list	*elem;

	lst = sorted;
	while (lst)
	{
		elem = a;
		while (elem->num != lst->num)
			elem = elem->next;
		elem->index = lst->index;
		lst = lst->next;
		if (lst == sorted)
			break ;
	}
}

void 	ft_support_sort(t_list **a, t_params *params)
{
	t_list	*first;
	t_list	*second;
	int		tmp;

	params->list_sorted = ft_copy_lst(*a);
	if (!params->list_sorted)
		ft_error(a, NULL);
	first = params->list_sorted;
	while (first->next != params->list_sorted)
	{
		second = first->next;
		while (second != params->list_sorted)
		{
			if (first->num > second->num)
			{
				tmp = first->num;
				first->num = second->num;
				second->num = tmp;
			}
			second = second->next;
		}
		first = first->next;
	}
	ft_set_index(*a, params->list_sorted);
}
