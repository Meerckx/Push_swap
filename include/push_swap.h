/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:40:58 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 13:23:13 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}				t_stack;

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	int		inaccuracy;
}				t_info;

void	init_stacks(int argc, char **argv, t_info *info);
t_stack	*parse_args(char **args, int size);
void	error(void);

void	sort(t_info	*info);
void	large_sort(t_info *info);
void	small_sort(t_info *info, int size);
int		is_min(t_stack *a, int b_index);
int		find_max_of_min(t_stack *a, int b_index);
int		find_min_of_max(t_stack *a, int b_index);
int		count_shift(t_stack *a, int b_index, int size);

t_stack	*create_stack(int data);
t_stack	*stack_prelast(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
void	stackadd_back(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
int		get_new_index(t_stack *stack, int new_data);
int		stack_size(t_stack *stack);
int		get_max_pos(t_stack *stack);
int		get_min_pos(t_stack *stack);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif