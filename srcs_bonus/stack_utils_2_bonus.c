/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:35:50 by eshana            #+#    #+#             */
/*   Updated: 2021/12/09 19:29:13 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_rr(t_list **a, t_list **b)
{
	if (*a)
		*a = (*a)->next;
	if (*b)
		*b = (*b)->next;
}

void	ft_do_rrr(t_list **a, t_list **b)
{
	if (*a)
		*a = ft_lstlast(*a);
	if (*b)
		*b = ft_lstlast(*b);
}
