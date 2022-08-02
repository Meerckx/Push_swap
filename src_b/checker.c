/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:26:03 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 19:48:17 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	use_command(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(line, "sa", 3))
		sa(a);
	else if (!ft_strncmp(line, "sb", 3))
		sb(b);
	else if (!ft_strncmp(line, "ss", 3))
		ss(a, b);
	else if (!ft_strncmp(line, "pa", 3))
		pa(a, b);
	else if (!ft_strncmp(line, "pb", 3))
		pb(a, b);
	else if (!ft_strncmp(line, "ra", 3))
		ra(a);
	else if (!ft_strncmp(line, "rb", 3))
		rb(b);
	else if (!ft_strncmp(line, "rr", 3))
		rr(a, b);
	else if (!ft_strncmp(line, "rra", 4))
		rra(a);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(b);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(a, b);
	else
		return (0);
	return (1);
}

static int	read_commands(t_info *info)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!use_command(line, &info->a, &info->b))
		{
			free(line);
			line = NULL;
			return (0);
		}
		free(line);
		line = NULL;
		line = get_next_line(0);
	}
	return (1);
}

static int	is_sorted(t_stack *a, t_stack *b)
{
	if (b)
		return (0);
	while (a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	init_stacks(argc, argv, &info);
	if (!read_commands(&info))
	{
		stack_clear(&info.a);
		stack_clear(&info.b);
		error();
	}
	if (is_sorted(info.a, info.b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	stack_clear(&info.a);
	stack_clear(&info.b);
	return (0);
}
