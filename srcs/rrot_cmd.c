/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:50:08 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:25:47 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra_cmd(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_b;
	t_stack *temp_a;

	temp_b = *stack_b;
	temp_a = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		while (temp_a->next)
		{
			temp_a = temp_a->next;
		}
		temp_a->next = *stack_a;
		(temp_a->prev)->next = NULL;
		(*stack_a)->prev = temp_a;
		(*stack_a) = temp_a;
		(*stack_a)->prev = NULL;
	}
}

void	rrb_cmd(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_b;
	t_stack *temp_a;

	temp_b = *stack_b;
	temp_a = *stack_a;
	if (*stack_b && (*stack_b)->next)
	{
		while (temp_b->next)
			temp_b = temp_b->next;
		temp_b->next = *stack_b;
		(temp_b->prev)->next = NULL;
		(*stack_b)->prev = temp_b;
		(*stack_b) = temp_b;
		(*stack_b)->prev = NULL;
	}
}

void	rrr_cmd(t_stack **stack_a, t_stack **stack_b)
{
	rra_cmd(stack_a, stack_b);
	rrb_cmd(stack_a, stack_b);
}
