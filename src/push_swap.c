/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:38:09 by anonymous         #+#    #+#             */
/*   Updated: 2022/04/10 19:47:14 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;

	init_stacks(argc, argv, &info);
	sort(&info);
	stack_clear(&info.a);
	stack_clear(&info.b);
	return (0);
}
