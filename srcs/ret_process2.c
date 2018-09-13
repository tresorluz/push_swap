/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_process2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:14:53 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/08 10:14:57 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		smallest_int(t_stack *sb)
{
	int		smallest;
	t_stack	*temp;

	temp = sb;
	smallest = temp->v;
	while (temp)
	{
		if (smallest > temp->v)
			smallest = temp->v;
		temp = temp->next;
	}
	return (smallest);
}

void	updatestack_rev(t_out *ret, t_onum op, t_stack **sa, t_stack **sb)
{
	t_out *temp;

	temp = ret;
	while (temp->next)
		temp = temp->next;
	temp->num = op;
	temp->next = outinit();
	do_op_rev(op, sa, sb);
}

void	updatestack(t_out *ret, t_onum op, t_stack **sa, t_stack **sb)
{
	t_out *temp;

	temp = ret;
	while (temp->next)
		temp = temp->next;
	temp->num = op;
	temp->next = outinit();
	do_op(op, sa, sb);
}

void	ret_printing(t_out *ret)
{
	int i;

	i = 0;
	while (ret)
	{
		if (ret->num == NOTHING)
			break ;
		print_cmds2(ret->num);
		ret = ret->next;
		i++;
	}
}

int		ret_number(t_out *ret)
{
	int i;

	i = 0;
	while (ret->num != NOTHING)
	{
		i++;
		ret = ret->next;
	}
	return (i);
}
