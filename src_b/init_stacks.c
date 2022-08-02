/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:49:17 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/20 13:20:26 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_args_size(char **args)
{
	int	size;

	if (!args)
		return (0);
	size = 0;
	while (args[size])
		size++;
	return (size);
}

static void	args_free(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args);
	args = NULL;
}

void	init_stacks(int argc, char **argv, t_info *info)
{
	char	**args;

	info->a = NULL;
	info->b = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		info->a = parse_args(args, get_args_size(args));
		args_free(args);
	}
	else if (argc > 2)
		info->a = parse_args(&argv[1], argc - 1);
	if (!info->a)
		error();
}
