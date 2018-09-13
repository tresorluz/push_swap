/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:54:22 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:20:59 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		is_rev_ordered(t_stack *stack_a, t_stack *stack_b)
{
	int temp;

	if (stack_a)
		return (0);
	else if (!(stack_b))
		return (0);
	temp = stack_b->v;
	while (stack_b->next)
	{
		if ((stack_b->next)->v < temp)
			temp = (stack_b->next)->v;
		else if ((stack_b->next)->v == temp)
			return (2);
		else
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int		rev_ordered(t_stack *stack_b)
{
	int temp;

	if (!(stack_b))
		return (0);
	temp = stack_b->v;
	while (stack_b->next)
	{
		if ((stack_b->next)->v < temp)
			temp = (stack_b->next)->v;
		else if ((stack_b->next)->v == temp)
			return (2);
		else
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int		ordered(t_stack *stack_b)
{
	int temp;

	if (!(stack_b))
		return (0);
	temp = stack_b->v;
	while (stack_b->next)
	{
		if ((stack_b->next)->v > temp)
			temp = (stack_b->next)->v;
		else if ((stack_b->next)->v == temp)
			return (2);
		else
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

int		almost_ordered(t_stack *stack_b)
{
	int temp;
	int temp2;

	if (!(stack_b))
		return (1);
	if (ordered(stack_b))
		return (1);
	temp = stack_b->v;
	temp2 = stack_b->v;
	if (almost_ordered2(stack_b, temp, temp2))
		return (1);
	else
		return (0);
	return (0);
}

int		almost_ordered2(t_stack *stack_b, int temp, int temp2)
{
	int flag;

	flag = 0;
	while (stack_b)
	{
		if (!(stack_b->next))
			break ;
		if ((stack_b->next)->v > temp)
			temp = (stack_b->next)->v;
		else if ((stack_b->next)->v == temp)
			return (1);
		else if (flag == 0)
			flag++;
		else
			return (0);
		stack_b = stack_b->next;
	}
	if (flag == 1 && stack_b->v < temp2)
		return (1);
	return (0);
}
