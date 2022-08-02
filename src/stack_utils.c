/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:03:38 by anonymous         #+#    #+#             */
/*   Updated: 2022/03/31 18:19:59 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_stack(int data)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack)
	{
		stack->data = data;
		stack->index = 0;
		stack->next = NULL;
	}
	return (stack);
}

t_stack	*stack_prelast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = stack_last(*stack);
	if (new)
	{
		new->index = get_new_index(*stack, new->data);
		if (!last)
			(*stack) = new;
		else
			last->next = new;
	}
}

void	stack_clear(t_stack **stack)
{
	t_stack	*current;

	if (!(*stack))
		return ;
	while (*stack)
	{
		current = (*stack);
		(*stack) = (*stack)->next;
		free(current);
		current = NULL;
	}
}
