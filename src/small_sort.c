/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:38:39 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 19:47:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_elems(t_stack **a, int first, int second, int third)
{
	if (!(*a))
		return ;
	if (first < second && first < third && second > third)
	{
		rra(a);
		sa(a);
	}
	else if (first > second && first < third && second < third)
		sa(a);
	else if (first < second && first > third && second > third)
		rra(a);
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first > second && first > third && second > third)
	{
		sa(a);
		rra(a);
	}
}

void	shift_stack_a(t_stack **a, int shift)
{
	if (!(*a))
		return ;
	while (shift > 0)
	{
		ra(a);
		shift--;
	}
	while (shift < 0)
	{
		rra(a);
		shift++;
	}
}

void	set_a_order(t_stack **a, int size)
{
	int		min_position;

	if (!(*a))
		return ;
	min_position = get_min_pos(*a);
	if (min_position > size / 2)
	{
		while (size - min_position != 0)
		{
			rra(a);
			min_position++;
		}
	}
	else
	{
		while (min_position != 0)
		{
			ra(a);
			min_position--;
		}
	}
}

void	sort_more_than_three(t_stack **a, t_stack **b)
{
	int	size;
	int	shift;

	if (!(*a))
		return ;
	while (stack_size(*a) != 3)
		pb(a, b);
	sort_three_elems(a, (*a)->index, (*a)->next->index,
		(*a)->next->next->index);
	size = 3;
	while (*b)
	{
		shift = count_shift(*a, (*b)->index, size);
		shift_stack_a(a, shift);
		pa(a, b);
		size++;
	}
	set_a_order(a, size);
}

void	small_sort(t_info *info, int size)
{
	if (size == 2)
		sa(&info->a);
	else if (size == 3)
		sort_three_elems(&info->a, info->a->index, info->a->next->index,
			info->a->next->next->index);
	else
		sort_more_than_three(&info->a, &info->b);
}
