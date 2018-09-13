/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:40:10 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/08 10:13:05 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../libft/libft.h"

void	processop(t_stack **stack_a, t_stack **stack_b, t_op *oplist, int debug)
{
	t_op	*begin;

	begin = oplist;
	if (!(begin->fp))
		return ;
	if (debug > 0)
	{
		ft_putstr_fd("YOU ARE IN DEBUG MODE\n", 2);
		debug_ops(oplist);
		debug_pstacks(*stack_a, *stack_b);
	}
	while (begin)
	{
		begin->fp(stack_a, stack_b);
		if (debug > 0)
		{
			print_cmds(begin->op);
			debug_pstacks(*stack_a, *stack_b);
		}
		begin = begin->next;
	}
}

int		is_ordered(t_stack *stack_a, t_stack *stack_b)
{
	int temp;

	if (stack_b)
		return (0);
	else if (!(stack_a))
		return (0);
	temp = stack_a->v;
	while (stack_a->next)
	{
		if ((stack_a->next)->v > temp)
			temp = (stack_a->next)->v;
		else if ((stack_a->next)->v == temp)
			return (2);
		else
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_op	*oplist;
	t_stack	*stack_a;
	t_stack *stack_b;
	int		temp;

	temp = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (!(stack_a = valid_input(ac, av, stack_a)))
		return (0);
	oplist = get_ops();
	if (!(ft_strcmp("-v", av[1])))
		temp = 1;
	processop(&stack_a, &stack_b, oplist, temp);
	if ((temp = is_ordered(stack_a, stack_b)))
	{
		if (temp == 1)
			ft_putstr("OK\n");
		else
			write(2, "Error\n", 6);
	}
	else
		ft_putstr("KO\n");
	return (0);
}
