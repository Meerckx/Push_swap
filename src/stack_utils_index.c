/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:12:49 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/05 02:00:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_new_index(t_stack *stack, int new_data)
{
	long long	counter;

	if (!stack)
		return (0);
	counter = 0;
	while (stack)
	{
		if (new_data < stack->data)
			stack->index++;
		else
			counter++;
		stack = stack->next;
	}
	return (counter);
}

int	stack_size(t_stack *stack)
{
	int	size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	get_max_pos(t_stack *stack)
{
	int	n;
	int	max_pos;
	int	max;

	if (!stack)
		return (-1);
	n = 0;
	max = -1;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			max_pos = n;
		}
		n++;
		stack = stack->next;
	}
	return (max_pos);
}

int	get_min_pos(t_stack *stack)
{
	int	n;
	int	min_pos;
	int	min;

	if (!stack)
		return (-1);
	n = 1;
	min_pos = 0;
	min = stack->index;
	stack = stack->next;
	while (stack)
	{
		if (stack->index < min)
		{
			min = stack->index;
			min_pos = n;
		}
		n++;
		stack = stack->next;
	}
	return (min_pos);
}
