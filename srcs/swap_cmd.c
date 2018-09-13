/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:48:16 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:26:26 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa_cmd(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a;
	t_stack *temp_b;

	temp_b = *stack_b;
	if (*stack_a && (*stack_a)->next)
	{
		temp_a = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		temp_a->next = (*stack_a)->next;
		temp_a->prev = (*stack_a);
		(*stack_a)->next = temp_a;
		(*stack_a)->prev = NULL;
	}
	temp_a = *stack_a;
	while (temp_a->next)
	{
		(temp_a->next)->prev = temp_a;
		temp_a = temp_a->next;
	}
}

void	sb_cmd(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a;
	t_stack *temp_b;

	temp_a = *stack_a;
	if (*stack_b && (*stack_b)->next)
	{
		temp_b = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		temp_b->next = (*stack_b)->next;
		temp_b->prev = (*stack_b);
		(*stack_b)->next = temp_b;
		(*stack_b)->prev = NULL;
	}
	temp_b = *stack_b;
	while (temp_b->next)
	{
		(temp_b->next)->prev = temp_b;
		temp_b = temp_b->next;
	}
}

void	ss_cmd(t_stack **stack_a, t_stack **stack_b)
{
	sa_cmd(stack_a, stack_b);
	sb_cmd(stack_a, stack_b);
}
