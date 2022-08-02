/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:48:52 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 18:54:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
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

t_stack	*create_stack(int data);
t_stack	*stack_prelast(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
void	stackadd_back(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
int		get_new_index(t_stack *stack, int new_data);

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