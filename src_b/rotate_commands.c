/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:44:25 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 19:08:25 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	last = stack_last(*a);
	*a = (*a)->next;
	first->next = NULL;
	last->next = first;
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	last = stack_last(*b);
	*b = (*b)->next;
	first->next = NULL;
	last->next = first;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
