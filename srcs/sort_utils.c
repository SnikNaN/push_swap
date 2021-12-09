/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:39:07 by eshana            #+#    #+#             */
/*   Updated: 2021/12/08 21:16:43 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_choose_strategy(const unsigned int score[4])
{
	if (score[0] <= score[1] && score[0] <= score[2] && score[0] <= score[3])
		return (0);
	if (score[1] <= score[0] && score[1] <= score[2] && score[1] <= score[3])
		return (1);
	if (score[2] <= score[0] && score[2] <= score[1] && score[2] <= score[3])
		return (2);
	return (3);
}

static void	ft_find_score(t_list *a, t_list *b, t_list *elem, t_list *aim)
{
	unsigned int	score[4];
	unsigned int	aim_height;
	unsigned int	elem_height;
	unsigned int	aim_bottom;
	unsigned int	elem_bottom;

	aim_height = ft_elem_height(a, aim);
	elem_height = ft_elem_height(b, elem);
	aim_bottom = ft_list_size(a) - aim_height;
	elem_bottom = ft_list_size(b) - elem_height;
	if (aim_height > elem_height)
		score[RR] = aim_height;
	else
		score[RR] = elem_height;
	score[RB_RRA] = elem_height + aim_bottom;
	score[RRB_RA] = elem_bottom + aim_height;
	if (aim_bottom > elem_bottom)
		score[RRR] = aim_bottom;
	else
		score[RRR] = elem_bottom;
	elem->strategy = ft_choose_strategy(score);
	elem->score = score[elem->strategy];
}

t_list	*ft_find_minimal_score(t_list *a, t_list *b)
{
	t_list	*lst;
	t_list	*res;

	lst = b;
	res = lst;
	while (lst)
	{
		lst->aim = ft_find_place(a, lst);
		ft_find_score(a, b, lst, lst->aim);
		if (lst->score < res->score)
			res = lst;
		lst = lst->next;
		if (lst == b)
			break ;
	}
	return (res);
}

static void	ft_parallel_ops(t_list **a, t_list **b, t_list *elem)
{
	if (elem->strategy == RR)
	{
		while (*a != elem->aim && *b != elem)
			ft_do_rr(a, b);
		while (*a != elem->aim)
			ft_do_ra(a);
		while (*b != elem)
			ft_do_rb(b);
	}
	else
	{
		while (*a != elem->aim && *b != elem)
			ft_do_rrr(a, b);
		while (*a != elem->aim)
			ft_do_rra(a);
		while (*b != elem)
			ft_do_rrb(b);
	}
}

void	ft_place(t_list **a, t_list **b, t_list *elem)
{
	if (elem->strategy == RR || elem->strategy == RRR)
		ft_parallel_ops(a, b, elem);
	else if (elem->strategy == RB_RRA)
	{
		while (*b != elem)
			ft_do_rb(b);
		while (*a != elem->aim)
			ft_do_rra(a);
	}
	else if (elem->strategy == RRB_RA)
	{
		while (*b != elem)
			ft_do_rrb(b);
		while (*a != elem->aim)
			ft_do_ra(a);
	}
	ft_do_pa(a, b);
}
