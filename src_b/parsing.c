/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:59:52 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 13:43:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_valid_arg(char *arg)
{
	int			i;
	int			sign;
	long long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i++] == '-')
			sign = -1;
	}
	while (arg[i])
	{
		if (ft_isdigit(arg[i]))
		{
			number = number * 10 + (arg[i] - '0');
			if ((number * sign) > INT_MAX || (number * sign) < INT_MIN)
				return (0);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

static int	is_dublicated(t_stack *stack)
{
	t_stack	*i_stack;
	t_stack	*j_stack;

	if (!stack)
		return (0);
	i_stack = stack;
	while (i_stack->next)
	{
		j_stack = i_stack->next;
		while (j_stack)
		{
			if (i_stack->data == j_stack->data)
				return (1);
			j_stack = j_stack->next;
		}
		i_stack = i_stack->next;
	}
	return (0);
}

t_stack	*parse_args(char **args, int size)
{
	t_stack	*a;
	int		i;

	if (!args)
		return (0);
	i = 0;
	while (i < size)
	{
		if (!is_valid_arg(args[i]) || args[i][0] == '\0')
			return (NULL);
		i++;
	}
	i = 0;
	while (i < size)
		stackadd_back(&a, create_stack(ft_atoi(args[i++])));
	if (is_dublicated(a))
	{
		stack_clear(&a);
		return (NULL);
	}
	return (a);
}
