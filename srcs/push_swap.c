/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:49:03 by eshana            #+#    #+#             */
/*   Updated: 2021/11/28 19:08:20 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_min_max(t_list *lst, t_params	*params)
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

void 	ft_sort_3(t_list *a, t_params params)
{
	ft_find_min_max(a, &params);
	if (ft_lstlast(a)->index == params.max)
	{
		if (a->index == params.min)
			return ;
		ft_putstr("sa\n");
	}
	else if (a->index == params.min)
		ft_putstr("sa\nra\n");
	else if (a->next->index == params.min)
		ft_putstr("ra\n");
	else if (a->next->index == params.max)
		ft_putstr("rra\n");
	else
		ft_putstr("sa\nrra\n");
}

void	ft_sort_4(t_list **a, t_list **b,  t_params *params)
{
	if ((*a)->next->index == 0)
		ft_do_ra(a);
	else
	{
		while ((*a)->index != 0)
			ft_do_rra(a);
	}
	ft_check_sort(a);
	ft_do_pb(a, b);
	ft_sort_3(*a, *params);
	ft_do_pa(a, b);
}

void 	ft_sort_5(t_list **a, t_list **b, t_params *params)
{
	if ((*a)->next->index == 0 || (*a)->next->next->index == 0)
	{
		while ((*a)->index != 0)
		{
			if ((*a)->index == 1)
				ft_do_pb(a, b);
			else
				ft_do_ra(a);
		}
	}
	else
	{
		while ((*a)->index != 0)
		{
			if ((*a)->index == 1)
				ft_do_pb(a, b);
			else
				ft_do_rra(a);
		}
	}
	ft_do_pb(a, b);
	if ((*b)->next == *b)
	{
		if ((*a)->next->index == 1)
			ft_do_ra(a);
		else
		{
			while ((*a)->index != 1)
				ft_do_rra(a);
		}
		ft_do_pb(a, b);
	}
	ft_sort_3(*a, *params);
	if ((*b)->index < (*b)->next->index)
		ft_putstr("rb\n");
	ft_putstr("pa\npa\n");
}

void	ft_find_longest_subseq(t_list *a, t_params *params)
{
	t_list		*begin;
	t_list		*end;
	unsigned int	size;
	int		flag;

	size = 1;
	flag = 0;
	begin = a;
	end = begin;
	params->max_sorted_cnt = 0;
	while (begin)
	{
		if (size > params->max_sorted_cnt)
		{
			params->max_sorted_cnt = size;
			params->max_sorted_begin = begin;
			params->max_sorted_end = end;
		}
		if (end->next->num < end->num)
		{
			begin = end->next;
			end = begin;
			size = 1;
			if (flag || end == a)
				break;
			continue ;
		}
		size++;
		end = end->next;
		if (end == a)
			flag = 1;
		if (end == begin)
			break ;
	}
}

unsigned int	ft_list_size(t_list *a)
{
	t_list		*lst;
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
	while (!((a->index < ft_lstlast(a)->index && (elem->index > ft_lstlast(a)->index || (elem)->index < a->index)) || (a->index > elem->index && ft_lstlast(a)->index < elem->index)))
		a = a->next;
	return (a);
}

//unsigned long long	*ft_count_score(t_list *a, t_list *b, t_list *aim, t_list *elem)
//{
//	unsigned int	height_aim;
//	unsigned int 	height_elem;
//	unsigned int 	a_size;
//	unsigned int	b_size;
//
//	height_aim = ft_elem_height(a, aim);
//	height_elem = ft_elem_height(b, elem);
//	a_size = ft_list_size(a);
//	b_size = ft_list_size(b);
//}

unsigned long long	ft_min(const unsigned long long score[4])
{
	if (score[0] <= score[1] && score[0] <= score[2] && score[0] <= score[3])
		return (score[0]);
	if (score[1] <= score[0] && score[1] <= score[2] && score[1] <= score[3])
		return (score[1]);
	if (score[2] <= score[0] && score[2] <= score[1] && score[2] <= score[3])
		return (score[2]);
	return (score[3]);
}

int	ft_choose_strategy(const unsigned long long score[4])
{
	if (score[0] <= score[1] && score[0] <= score[2] && score[0] <= score[3])
		return (0);
	if (score[1] <= score[0] && score[1] <= score[2] && score[1] <= score[3])
		return (1);
	if (score[2] <= score[0] && score[2] <= score[1] && score[2] <= score[3])
		return (2);
	return (3);
}

void	ft_find_score(t_list *a, t_list *b, t_list *elem, t_list *aim)
{
	unsigned long long	score[4];
	unsigned int 		aim_height;
	unsigned int 		elem_height;
	unsigned int		aim_bottom;
	unsigned int 		elem_bottom;

	aim_height = ft_elem_height(a, aim);
	elem_height = ft_elem_height(b, elem);
	aim_bottom = ft_list_size(a) - aim_height;
	elem_bottom = ft_list_size(b) - elem_height;
	if (aim_height > elem_height)
		score[0] = aim_height;
	else
		score[0] = elem_height;
	score[1] = elem_height + aim_bottom;
	score[2] = elem_bottom + aim_height;
	if (aim_bottom > elem_bottom)
		score[3] = aim_bottom;
	else
		score[3] = elem_bottom;
	elem->score = ft_min(score);
	elem->strategy = ft_choose_strategy(score);
}

t_list 	*ft_minimal_score(t_list *a, t_list *b)
{
	t_list	*lst;
	t_list	*aim;
	t_list	*res;

	lst = b;
	res = lst;
	while (lst)
	{
		aim = ft_find_place(a, lst);
		ft_find_score(a, b, lst, aim);
		if (lst->score < res->score)
			res = lst;
		lst = lst->next;
		if (lst == b)
			break ;
	}
	return (res);
}

void	ft_place_elem(t_list **a, t_list **b, t_list *elem, t_list *aim)
{
	if (elem->strategy == 0)
	{
		while (*a != aim && *b != elem)
			ft_do_rr(a, b);
		while (*a != aim)
			ft_do_ra(a);
		while (*b != elem)
			ft_do_rb(b);
	}
	else if (elem->strategy == 1)
	{
		while (*b != elem)
			ft_do_rb(b);
		while (*a != aim)
			ft_do_rra(a);
	}
	else if (elem->strategy == 2)
	{
		while (*b != elem)
			ft_do_rrb(b);
		while (*a != aim)
			ft_do_ra(a);
	}
	else
	{
		while (*a != aim && *b != elem)
			ft_do_rrr(a, b);
		while (*a != aim)
			ft_do_rra(a);
		while (*b != elem)
			ft_do_rrb(b);
	}
	ft_do_pa(a, b);
}

void	ft_sort(t_list **a, t_list **b, t_params *params)
{
	t_list	*elem;
	t_list	*aim;

	if (ft_list_size(*a) == params->max_sorted_cnt)
	{
		while (*a != params->max_sorted_begin)
			ft_do_ra(a);
		return ;
	}
	if (ft_elem_height(*a, params->max_sorted_end)
			< ft_elem_height(*a, params->max_sorted_begin))
	{
		if (ft_elem_height(*a, params->max_sorted_end) <
 ft_list_size(*a) / 2)                                                  	while (ft_lstlast(*a) !=
 				params->max_sorted_end)
	 		ft_do_ra(a);
        	else
                	while (ft_lstlast(*a) != params->max_sorted_end)
                        ft_do_rra(a);
	}
	while (*a != params->max_sorted_begin)
		ft_do_pb(a, b);////
	if (ft_elem_height(*a, params->max_sorted_end) < ft_list_size(*a) / 2)
		while (ft_lstlast(*a) != params->max_sorted_end)
			ft_do_ra(a);
	else
		while (ft_lstlast(*a) != params->max_sorted_end)
			ft_do_rra(a);
	while (*a != params->max_sorted_begin)
		ft_do_pb(a, b);
	while (*b)
	{
		elem = ft_minimal_score(*a, *b);
		aim = ft_find_place(*a, elem);
		ft_place_elem(a, b, elem, aim);
	}
	elem = *a;
	while (elem->index)
		elem = elem->next;
	if (ft_elem_height(*a, elem) < ft_list_size(*a) / 2)
	{
		while ((*a)->index)
			ft_do_ra(a);
	}
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
	if (params.cnt == 2)
	{
		if (a->num > a->next->num)
			ft_putstr("ra\n");
	}
	else
	{
		ft_support_sort(&a, &params);
		if (params.cnt == 3)
			ft_sort_3(a, params);
		else if (params.cnt == 4)
			ft_sort_4(&a, &b, &params);
		else if (params.cnt == 5)
			ft_sort_5(&a, &b, &params);
		else
		{
			ft_find_longest_subseq(a, &params);
			ft_sort(&a, &b, &params);
		}
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	ft_lstclear(&params.list_sorted);
	return (0);
}
