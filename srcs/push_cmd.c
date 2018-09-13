/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:47:21 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:24:06 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fpb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	temp = *stack_a;
	if (*stack_a)
	{
		if (!(*stack_b))
		{
			*stack_b = *stack_a;
			*stack_a = (*stack_a)->next;
			(*stack_b)->next = NULL;
			(*stack_b)->prev = NULL;
		}
		else
		{
			*stack_a = (*stack_a)->next;
			temp->next = (*stack_b);
			(*stack_b)->prev = temp;
			*stack_b = temp;
		}
	}
	if (*stack_a)
	{
		(*stack_a)->prev = NULL;
	}
}

void	fpa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	temp = *stack_b;
	if (*stack_b)
	{
		if (!(*stack_a))
		{
			*stack_a = *stack_b;
			*stack_b = (*stack_b)->next;
			(*stack_a)->next = NULL;
			(*stack_a)->prev = NULL;
		}
		else
		{
			*stack_b = (*stack_b)->next;
			temp->next = (*stack_a);
			(*stack_a)->prev = temp;
			*stack_a = temp;
		}
	}
	if (*stack_b)
	{
		(*stack_b)->prev = NULL;
	}
}
