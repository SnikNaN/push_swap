/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:27:46 by eshana            #+#    #+#             */
/*   Updated: 2021/12/09 04:03:16 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define NUM_ERROR -2147483650

enum	e_strategies
{
	RR,
	RB_RRA,
	RRB_RA,
	RRR
};

typedef struct s_list
{
	int					num;
	unsigned int		score;
	unsigned int		strategy;
	unsigned int		index;
	struct s_list		*next;
	struct s_list		*aim;
}	t_list;

typedef struct s_params
{
	unsigned int	min;
	unsigned int	max;
	unsigned int	cnt;
	unsigned int	max_sorted_cnt;
	t_list			*max_sorted_begin;
	t_list			*max_sorted_end;
	t_list			*list_sorted;
}	t_params;

t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstnew(int num);
void			ft_lstclear(t_list **lst);
unsigned int	ft_read_nums(t_list **a, int argc, char **argv);
void			ft_error(t_list **lst_a, t_list **lst_b);
void			ft_putstr(char *str);
void			ft_puterr(char *msg);
void			ft_support_sort(t_list	**a, t_params *params);
unsigned int	ft_list_size(t_list *a);
unsigned int	ft_elem_height(t_list *begin, t_list *elem);

void			ft_do_sa(t_list **a);
void			ft_do_ra(t_list **a);
void			ft_do_rra(t_list **a);
void			ft_do_pa(t_list **a, t_list **b);

void			ft_do_pb(t_list **a, t_list **b);
void			ft_do_rb(t_list **b);
void			ft_do_rrb(t_list **b);

void			ft_do_rr(t_list **a, t_list **b);
void			ft_do_rrr(t_list **a, t_list **b);
void			ft_do_ss(t_list **a, t_list **b);

int				ft_check_sort(t_list **a);
void			ft_find_min_max(t_list *lst, t_params *params);
t_list			*ft_find_minimal_score(t_list *a, t_list *b);
void			ft_place(t_list **a, t_list **b, t_list *elem);
t_list			*ft_find_place(t_list *a, t_list *elem);
#endif
