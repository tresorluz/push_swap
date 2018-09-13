/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:49:14 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:25:17 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra_cmd(t_stack **stack_a, t_stack **stack_b)
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
		*stack_a = (*stack_a)->next;
		(temp_a->next)->next = NULL;
		(temp_a->next)->prev = temp_a;
	}
	(*stack_a)->prev = NULL;
}

void	rb_cmd(t_stack **stack_a, t_stack **stack_b)
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
		*stack_b = (*stack_b)->next;
		(temp_b->next)->next = NULL;
		(temp_b->next)->prev = temp_b;
	}
	(*stack_b)->prev = NULL;
}

void	rr_cmd(t_stack **stack_a, t_stack **stack_b)
{
	ra_cmd(stack_a, stack_b);
	rb_cmd(stack_a, stack_b);
}
