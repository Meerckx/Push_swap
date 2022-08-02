/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:19:08 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 13:24:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_min(t_stack *a, int b_index)
{
	while (a)
	{
		if (a->index < b_index)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_max_of_min(t_stack *a, int b_index)
{
	int	shift;
	int	nearest;
	int	n;

	n = 0;
	nearest = -1;
	shift = 0;
	while (a)
	{
		if (a->index > nearest && a->index < b_index)
		{
			shift = n;
			nearest = a->index;
		}
		n++;
		a = a->next;
	}
	shift++;
	return (shift);
}

int	find_min_of_max(t_stack *a, int b_index)
{
	int	shift;
	int	nearest;
	int	n;

	n = 0;
	nearest = 5;
	shift = 0;
	while (a)
	{
		if (a->index < nearest && a->index > b_index)
		{
			shift = n;
			nearest = a->index;
		}
		n++;
		a = a->next;
	}
	return (shift);
}

int	count_shift(t_stack *a, int b_index, int size)
{
	int	shift;

	if (!is_min(a, b_index))
		shift = find_max_of_min(a, b_index);
	else
		shift = find_min_of_max(a, b_index);
	if (shift > size / 2)
		return (shift - size);
	return (shift);
}
