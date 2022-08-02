/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:12:27 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 19:47:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	make_stack_b(t_stack **a, t_stack **b, int inaccuracy)
{
	int	counter;

	counter = 0;
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			pb(a, b);
			rb(b);
			counter++;
		}
		else if ((*a)->index <= counter + inaccuracy)
		{
			pb(a, b);
			counter++;
		}
		else
			ra(a);
	}
}

void	set_right_pos(t_stack **b, int size, int max_position)
{
	if (!(*b))
		return ;
	if (max_position > size / 2)
	{
		while (size - max_position != 0)
		{
			rrb(b);
			max_position++;
		}
	}
	else
	{
		while (max_position != 0)
		{
			rb(b);
			max_position--;
		}
	}
}

void	make_a_sorted(t_stack **a, t_stack **b)
{
	int	size;
	int	max_position;

	while (*b)
	{
		size = stack_size(*b);
		max_position = get_max_pos(*b);
		if (max_position == -1)
			return ;
		set_right_pos(b, size, max_position);
		pa(a, b);
	}
}

void	large_sort(t_info *info)
{
	make_stack_b(&info->a, &info->b, info->inaccuracy);
	make_a_sorted(&info->a, &info->b);
}
