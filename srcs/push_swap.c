/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:49:03 by eshana            #+#    #+#             */
/*   Updated: 2021/12/08 20:40:47 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **a, t_params params)
{
	ft_find_min_max(*a, &params);
	if (ft_lstlast(*a)->index == params.max)
	{
		if ((*a)->index == params.min)
			return ;
		ft_do_sa(a);
	}
	else if ((*a)->index == params.min)
	{
		ft_do_sa(a);
		ft_do_ra(a);
	}
	else if ((*a)->next->index == params.min)
		ft_do_ra(a);
	else if ((*a)->next->index == params.max)
		ft_do_rra(a);
	else
	{
		ft_do_sa(a);
		ft_do_rra(a);
	}
}

void	ft_sort_5(t_list **a, t_list **b, t_params *params)
{
	while ((*a)->index != 0)
		if ((*a)->index == 1)
			ft_do_pb(a, b);
	else
	{
		if ((*a)->next->index == 0 || (*a)->next->next->index == 0)
			ft_do_ra(a);
		else
			ft_do_rra(a);
	}
	ft_do_pb(a, b);
	if ((*b)->next == *b)
	{
		if ((*a)->next->index == 1)
			ft_do_ra(a);
		else
			while ((*a)->index != 1)
				ft_do_rra(a);
		ft_do_pb(a, b);
	}
	ft_sort_3(a, *params);
	if ((*b)->index < (*b)->next->index)
		ft_putstr("rb\n");
	ft_putstr("pa\npa\n");
}

void	ft_sort(t_list **a, t_list **b, t_params *params)
{
	t_list	*elem;

	ft_find_min_max(*a, params);
	while (ft_list_size(*a) > 3)
	{
		ft_do_pb(a, b);
		if (((*b)->index > params->max / 2) && (ft_list_size(*b) > 1))
			ft_do_rb(b);
	}
	ft_sort_3(a, *params);
	while (*b)
	{
		elem = ft_find_minimal_score(*a, *b);
		ft_place(a, b, elem);
	}
	elem = *a;
	while (elem->index)
		elem = elem->next;
	if (ft_elem_height(*a, elem) < ft_list_size(*a) / 2)
		while ((*a)->index)
			ft_do_ra(a);
	else
		while ((*a)->index)
			ft_do_rra(a);
}

int	main(int argc, char **argv)
{
	t_list			*a;
	t_list			*b;
	t_params		params;

	a = NULL;
	b = NULL;
	params.cnt = ft_read_nums(&a, argc, argv);
	ft_support_sort(&a, &params);
	if (params.cnt == 2)
	{
		if (a->num > a->next->num)
			ft_putstr("ra\n");
	}
	else if (params.cnt == 3)
		ft_sort_3(&a, params);
	else if (params.cnt == 5)
		ft_sort_5(&a, &b, &params);
	else
		ft_sort(&a, &b, &params);
	ft_lstclear(&a);
	ft_lstclear(&b);
	ft_lstclear(&params.list_sorted);
	return (0);
}
