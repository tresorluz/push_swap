/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:07:23 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:24:20 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	cleanup(t_stack **sa, t_stack **sb, t_out **ret)
{
	t_stack *next;
	t_out	*nexto;

	nexto = *ret;
	next = *sa;
	while (next)
	{
		next = (*sa)->next;
		free(*sa);
		*sa = next;
	}
	next = *sb;
	while (next)
	{
		next = (*sb)->next;
		free(*sb);
		*sb = next;
	}
	while (nexto)
	{
		nexto = (*ret)->next;
		free(*ret);
		*ret = nexto;
	}
}

int			main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_out	*ret;

	stack_a = NULL;
	stack_b = NULL;
	if (!(stack_a = valid_input(ac, av, stack_a)))
		return (0);
	ret = outinit();
	sort_algo(&stack_a, &stack_b, ret);
	ret_printing(ret);
	cleanup(&stack_a, &stack_b, &ret);
	return (0);
}
