/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:33:04 by eshana            #+#    #+#             */
/*   Updated: 2021/11/28 16:26:44 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*begin_list;

	begin_list = lst;
	if (lst)
	{
		while (lst->next != begin_list)
			lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstnew(int num)
{
	t_list	*elem;

	elem = (t_list *) malloc(sizeof(t_list));
	if (elem)
	{
		elem->num = num;
		elem->score = 0;
		elem->index = 0;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst && new)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
		new->next = *lst;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst && new)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			new->next = *lst;
			*lst = new;
			last->next = new;
		}
		else
		{
			*lst = new;
			(*lst)->next = *lst;
		}
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*cur;

	if (lst)
	{
		cur = *lst;
		if (cur)
		{
			cur = cur->next;
			while (cur != *lst)
			{
				tmp = cur->next;
				free(cur);
				cur = tmp;
			}
			free(*lst);
			*lst = NULL;
		}
	}
}
