/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:24:54 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:21:37 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	phelp(t_stack *temp_a, t_stack *temp_b)
{
	if (temp_a && temp_b)
	{
		ft_putnbr_fd((temp_a)->v, 2);
		ft_putstr_fd("\t", 2);
		ft_putnbr_fd((temp_b)->v, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (temp_a)
	{
		ft_putnbr_fd((temp_a)->v, 2);
		ft_putstr_fd("\t", 2);
		ft_putstr_fd("\n", 2);
	}
	else if (temp_b)
	{
		ft_putstr_fd("\t\t", 2);
		ft_putnbr_fd(temp_b->v, 2);
		ft_putstr_fd("\n", 2);
	}
}

void		debug_pstacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *temp_a;
	t_stack *temp_b;

	temp_a = stack_a;
	temp_b = stack_b;
	ft_putstr_fd("Stack A\tStack B\n", 2);
	while (temp_a || temp_b)
	{
		phelp(temp_a, temp_b);
		if (temp_a && temp_b)
		{
			temp_a = (temp_a)->next;
			temp_b = (temp_b)->next;
		}
		else if (temp_a)
			temp_a = (temp_a)->next;
		else if (temp_b)
			temp_b = (temp_b)->next;
	}
}

int			debug_ops(t_op *begin)
{
	int i;

	i = 0;
	while (begin)
	{
		if (begin->op == nothing)
			break ;
		i++;
		print_cmds(begin->op);
		begin = begin->next;
	}
	ft_putstr_fd("Total number of Ops is:", 2);
	ft_putnbr_fd(i, 2);
	ft_putstr_fd("\n", 2);
	return (i);
}
