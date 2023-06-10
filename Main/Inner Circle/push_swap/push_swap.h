/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojin <seojin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:56:54 by seojin            #+#    #+#             */
/*   Updated: 2022/08/31 20:38:12 by seojin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "push_swap_macro.h"
# include "push_swap_struct.h"

/* func for main */
void	ft_push_swap(t_stack **a, t_stack **b, int len);
void	ft_quick_greedy_sort(t_stack **a, t_stack **b);
void	ft_optimize(t_stack **a, t_stack **b, int a_pos, int b_pos);

/* func for get pivot */
int		ft_get_pivot(t_stack *a, int standard);
int		ft_get_bigger_pivot(t_stack *a, int pivot);
int		ft_get_smaller_pivot(t_stack *a, int pivot);
int		ft_get_num(t_stack *a, int pivot);

/* func for init stack */
void	ft_exit(int code);
void	ft_free_lst(t_stack **head);
void	ft_append_back(t_stack **head, t_stack *node);
t_stack	*ft_init(char **av);
t_stack	*ft_new_node(int val);
t_stack	*ft_last_node(t_stack *node);
t_stack	*ft_before_last_node(t_stack *node);

/* func for hard sort */
void	ft_hard_sort(t_stack **a, t_stack **b, int len);
void	ft_sort_2(t_stack **a);
void	ft_sort_3(t_stack **a);
void	ft_sort_4(t_stack **a, t_stack **b);
void	ft_sort_5(t_stack **a, t_stack **b);
void	ft_sort_6(t_stack **a, t_stack **b);
void	ft_optimization(t_stack **a, t_stack **b, int min, int max);

/* simul instructions for hard sort */
void	ft_simul_rotate(t_stack **a);
void	ft_simul_reverse_rotate(t_stack **a);

/* instructions */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* etc util func */
int		ft_ascending_check(t_stack *stack);
int		ft_descending_check(t_stack *stack);
int		ft_lst_len(t_stack *lst);
int		ft_get_min(t_stack *stack);
int		ft_get_max(t_stack *stack);
int		ft_abs(int val);
int		ft_get_min_pos(t_stack *a, int min);
int		ft_get_valid_pos(t_stack *a, int val);
int		ft_get_min_movement(t_stack *stack);
int		ft_get_min_movement_pos(t_stack *stack, int movement);
int		ft_get_min_movement_val(t_stack *stack, int movement);
void	ft_get_movement_cnt(t_stack *a, t_stack *b);

/* func for checker */
void	csa(t_stack **a);
void	csb(t_stack **b);
void	css(t_stack **a, t_stack **b);
void	cpa(t_stack **a, t_stack **b);
void	cpb(t_stack **b, t_stack **a);
void	cra(t_stack **a);
void	crb(t_stack **b);
void	crr(t_stack **a, t_stack **b);
void	crra(t_stack **a);
void	crrb(t_stack **b);
void	crrr(t_stack **a, t_stack **b);
void	ft_error(t_stack **a, t_stack **b);
void	ft_verify(t_stack **a, t_stack **b);
void	ft_memmove(char *dst, char *src);
void	ft_verify2(t_stack **a, t_stack **b, char *s);
char	**ft_split(char const *s, char c);
char	*ft_glue(char *str, char buf);
int		cmp(char *s1, char *s2);

#endif
