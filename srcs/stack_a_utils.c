/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:39:57 by eshana            #+#    #+#             */
/*   Updated: 2021/12/08 19:39:57 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_ra(t_list **a)
{
	*a = (*a)->next;
	ft_putstr("ra\n");
}

void	ft_do_rra(t_list **a)
{
	*a = ft_lstlast(*a);
	ft_putstr("rra\n");
}

void	ft_do_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	if (*b == (*b)->next)
		*b = NULL;
	else
	{
		ft_lstlast(*b)->next = (*b)->next;
		(*b) = (*b)->next;
	}
	tmp->next = *a;
	ft_lstlast(*a)->next = tmp;
	*a = tmp;
	ft_putstr("pa\n");
}

void	ft_do_sa(t_list **a)
{
	t_list	*first;
	t_list	*last;

	first = *a;
	last = ft_lstlast(*a);
	*a = first->next;
	last->next = *a;
	first->next = (*a)->next;
	(*a)->next = first;
	ft_putstr("sa\n");
}
