/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:48:18 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 19:48:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	set_inaccuracy(int size)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size;
	mid = 0;
	while (high - low > 1)
	{
		mid = low + (high - low) / 2;
		if (mid * mid > size)
			high = mid;
		else
			low = mid;
	}
	return (mid);
}

int	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort(t_info	*info)
{
	int	size;

	size = stack_size(info->a);
	info->inaccuracy = set_inaccuracy(size * 2);
	if (is_sorted(info->a))
		return ;
	if (size <= 5)
		small_sort(info, size);
	else
		large_sort(info);
}
