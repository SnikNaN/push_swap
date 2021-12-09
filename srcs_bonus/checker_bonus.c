/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 03:48:06 by eshana            #+#    #+#             */
/*   Updated: 2021/12/09 21:48:06 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_read_input(char cmd[4])
{
	unsigned int	i;
	int				cnt;

	cnt = 1;
	i = 0;
	while (cnt > 0 && i < 4)
	{
		cnt = read(0, &cmd[i], 1);
		if (cnt == 0 && i == 0)
			return (0);
		if (cnt < 0)
			break ;
		if (cmd[i] == '\n')
		{
			cmd[i] = '\0';
			return (1);
		}
		i++;
	}
	cmd[0] = 'e';
	return (-1);
}

static int	ft_strcmp(const char str1[4], const char *str2)
{
	unsigned int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] != str2[i])
		return (0);
	return (1);
}

static void	ft_exec_cmd(char cmd[4], t_list **a, t_list **b)
{
	if (ft_strcmp(cmd, "sa"))
		ft_do_sa(a);
	else if (ft_strcmp(cmd, "ra"))
		ft_do_ra(a);
	else if (ft_strcmp(cmd, "rra"))
		ft_do_rra(a);
	else if (ft_strcmp(cmd, "pa"))
		ft_do_pa(a, b);
	else if (ft_strcmp(cmd, "sb"))
		ft_do_sa(b);
	else if (ft_strcmp(cmd, "rb"))
		ft_do_ra(b);
	else if (ft_strcmp(cmd, "rrb"))
		ft_do_rra(b);
	else if (ft_strcmp(cmd, "pb"))
		ft_do_pa(b, a);
	else if (ft_strcmp(cmd, "rr"))
		ft_do_rr(a, b);
	else if (ft_strcmp(cmd, "rrr"))
		ft_do_rrr(a, b);
	else if (ft_strcmp(cmd, "ss"))
		ft_do_ss(a, b);
	else
		ft_error(a, b);
}

int	main(int argc, char **argv)
{
	t_list			*a;
	t_list			*b;
	int				read_cnt;
	char			cmd[4];

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	read_cnt = 1;
	ft_read_nums(&a, argc, argv);
	while (read_cnt)
	{
		read_cnt = ft_read_input(cmd);
		if (read_cnt)
			ft_exec_cmd(cmd, &a, &b);
	}
	if (ft_check_sort(&a) && (b == NULL))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
