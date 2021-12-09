/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:35:50 by eshana            #+#    #+#             */
/*   Updated: 2021/12/09 19:29:13 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_ra(t_list **a)
{
	if (*a == NULL)
		return ;
	*a = (*a)->next;
}

void	ft_do_rra(t_list **a)
{
	if (*a == NULL)
		return ;
	*a = ft_lstlast(*a);
}

void	ft_do_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	if (*b == (*b)->next)
		*b = NULL;
	else
	{
		ft_lstlast(*b)->next = (*b)->next;
		(*b) = (*b)->next;
	}
	if (*a)
	{
		tmp->next = *a;
		ft_lstlast(*a)->next = tmp;
		*a = tmp;
	}
	else
	{
		*a = tmp;
		(*a)->next = *a;
	}
}

void	ft_do_sa(t_list **a)
{
	t_list	*first;
	t_list	*last;

	if (*a == NULL)
		return ;
	first = *a;
	last = ft_lstlast(*a);
	*a = first->next;
	last->next = *a;
	first->next = (*a)->next;
	(*a)->next = first;
}

void	ft_do_ss(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*last;

	if (*a)
	{
		first = *a;
		last = ft_lstlast(*a);
		*a = first->next;
		last->next = *a;
		first->next = (*a)->next;
		(*a)->next = first;
	}
	if (*b == NULL)
		return ;
	first = *b;
	last = ft_lstlast(*b);
	*b = first->next;
	last->next = *b;
	first->next = (*b)->next;
	(*b)->next = first;
}
