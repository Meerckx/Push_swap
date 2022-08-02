/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:12:49 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 18:53:33 by anonymous        ###   ########.fr       */
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
