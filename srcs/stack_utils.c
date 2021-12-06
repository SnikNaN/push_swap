/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:26:04 by eshana            #+#    #+#             */
/*   Updated: 2021/11/25 17:24:49 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen (const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && ((i + j) < (size - 1)))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}

void	ft_do_ra(t_list **a, t_params *params)
{
	*a = (*a)->next;
	ft_strlcat(params->str_out, "ra\n", 50000);
//	ft_putstr("ra\n");
}

void	ft_do_rra(t_list **a, t_params *params)
{
	*a = ft_lstlast(*a);
	ft_strlcat(params->str_out, "rra\n", 50000);
//	ft_putstr("rra\n");
}

void	ft_do_pb(t_list **a, t_list **b, t_params *params)
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
	ft_strlcat(params->str_out, "pb\n", 50000);
//	ft_putstr("pb\n");
}

void	ft_do_pa(t_list **a, t_list **b, t_params *params)
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
	ft_strlcat(params->str_out, "pa\n", 50000);
//	ft_putstr("pa\n");
}

void	ft_do_rb(t_list **b, t_params *params)
{
	*b = (*b)->next;
	ft_strlcat(params->str_out, "rb\n", 50000);
//	ft_putstr("rb\n");
}

void	ft_do_rrb(t_list **b, t_params *params)
{
	*b = ft_lstlast(*b);
	ft_strlcat(params->str_out, "rrb\n", 50000);
//	ft_putstr("rrb\n");
}

void 	ft_do_rr(t_list **a, t_list **b, t_params *params)
{
	*a = (*a)->next;
	*b = (*b)->next;
	ft_strlcat(params->str_out, "rr\n", 50000);
//	ft_putstr("rr\n");
}

void 	ft_do_rrr(t_list **a, t_list **b, t_params *params)
{
	*a = ft_lstlast(*a);
	*b = ft_lstlast(*b);
	ft_strlcat(params->str_out, "rrr\n", 50000);
//	ft_putstr("rrr\n");
}
