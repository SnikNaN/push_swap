/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:51:07 by eshana            #+#    #+#             */
/*   Updated: 2021/12/09 19:09:22 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list **lst_a, t_list **lst_b)
{
	ft_lstclear(lst_a);
	ft_lstclear(lst_b);
	ft_puterr("Error\n");
	exit(EXIT_FAILURE);
}

static long long int	ft_atoi(const char *str)
{
	unsigned int	i;
	long long int	res;
	int				sgn;

	sgn = 1;
	i = 0;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	if (!str[i])
		return (NUM_ERROR);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (NUM_ERROR);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sgn);
}

static void	ft_check_duplicates(t_list **a, int num)
{
	t_list	*lst;

	lst = *a;
	while (lst)
	{
		if (lst->num == num)
			ft_error(a, NULL);
		lst = lst->next;
		if (lst == *a)
			break ;
	}
}

int	ft_check_sort(t_list **a)
{
	t_list	*lst;

	lst = *a;
	if (lst)
	{
		while (lst->next)
		{
			if (lst->next->num < lst->num)
				return (0);
			lst = lst->next;
			if (lst->next == *a)
				break ;
		}
	}
	return (1);
}

unsigned int	ft_read_nums(t_list **a, int argc, char **argv)
{
	unsigned int	cnt;
	t_list			*tmp;
	long long int	num;

	cnt = 0;
	while (argc - cnt > 1)
	{
		num = ft_atoi(argv[cnt + 1]);
		if (num >= -2147483648 && num <= 2147483647)
		{
			ft_check_duplicates(a, num);
			tmp = ft_lstnew(num);
			if (!tmp)
				ft_error(a, NULL);
			ft_lstadd_back(a, tmp);
		}
		else
			ft_error(a, NULL);
		cnt++;
	}
	return (cnt);
}
