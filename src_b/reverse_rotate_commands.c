/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:17:39 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 19:08:18 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*prelast;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	last = stack_last(*a);
	prelast = stack_prelast(*a);
	*a = last;
	last->next = first;
	prelast->next = NULL;
}

void	rrb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*prelast;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	last = stack_last(*b);
	prelast = stack_prelast(*b);
	*b = last;
	last->next = first;
	prelast->next = NULL;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
