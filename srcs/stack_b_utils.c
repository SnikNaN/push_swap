/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:35:50 by eshana            #+#    #+#             */
/*   Updated: 2021/12/09 00:29:13 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	ft_lstlast(*a)->next = (*a)->next;
	(*a) = (*a)->next;
	if (*b)
	{
		tmp->next = *b;
		ft_lstlast(*b)->next = tmp;
		*b = tmp;
	}
	else
	{
		*b = tmp;
		(*b)->next = *b;
	}
	ft_putstr("pb\n");
}

void	ft_do_rb(t_list **b)
{
	*b = (*b)->next;
	ft_putstr("rb\n");
}

void	ft_do_rrb(t_list **b)
{
	*b = ft_lstlast(*b);
	ft_putstr("rrb\n");
}

void	ft_do_rr(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	ft_putstr("rr\n");
}

void	ft_do_rrr(t_list **a, t_list **b)
{
	*a = ft_lstlast(*a);
	*b = ft_lstlast(*b);
	ft_putstr("rrr\n");
}
