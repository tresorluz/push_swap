/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:53:10 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/08 10:16:30 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	insertbest(t_stack **sa, t_stack **sb, t_out *ret)
{
	t_stack	*temp;
	t_stack	*target;
	int		moves;

	temp = *sa;
	target = temp;
	moves = temp->moves;
	while (temp)
	{
		if (temp->moves < moves)
		{
			moves = temp->moves;
			target = temp;
		}
		temp = temp->next;
	}
	prepoprot(target, sa, sb, ret);
	updatestack(ret, PB, sa, sb);
}

static void	mergetwo(t_stack **sa, t_stack **sb, t_out *ret)
{
	while (*sb)
	{
		if ((*sb)->v > largest_int(*sa))
		{
			rotate_cor(ret, sa, sb, 0);
			updatestack(ret, PA, sa, sb);
		}
		else if ((*sb)->v < smallest_int(*sa))
		{
			rotate_cor(ret, sa, sb, 0);
			updatestack(ret, PA, sa, sb);
		}
		else if ((*sb)->v > (*sa)->v)
			updatestack(ret, RA, sa, sb);
		else if ((*sb)->v < (*sa)->v && (*sb)->v > (get_end(sa))->v)
			updatestack(ret, PA, sa, sb);
		else
			updatestack(ret, RRA, sa, sb);
	}
}

static int	sort_three(t_stack **sa, t_stack **sb, t_out *ret)
{
	if (stack_len(*sa) != 3)
		return (0);
	if ((*sa)->v == largest_int(*sa) && ((*sa)->next)->v < (get_end(sa))->v)
		return (1);
	else if ((*sa)->v > ((*sa)->next)->v)
		updatestack(ret, SA, sa, sb);
	else if ((*sa)->v == smallest_int(*sa) &&
			((*sa)->next)->v == largest_int(*sa))
		updatestack(ret, SA, sa, sb);
	return (1);
}

static int	sort_num(t_stack **sa, t_stack **sb, t_out *ret, int size)
{
	int i;
	int num;

	i = 0;
	num = size;
	if (stack_len(*sa) != num)
		return (0);
	while (i < (num - 3))
	{
		rotate_cor(ret, sa, sb, 0);
		updatestack(ret, PB, sa, sb);
		i++;
	}
	sort_three(sa, sb, ret);
	i = 0;
	while (i < (num - 3))
	{
		rotate_cor(ret, sa, sb, 0);
		updatestack(ret, PA, sa, sb);
		i++;
	}
	return (1);
}

void		sort_algo(t_stack **sa, t_stack **sb, t_out *ret)
{
	int i;
	int len;

	if (ordered(*sa) == 1)
		return ;
	i = 0;
	len = 3;
	if (stack_len(*sa) > 101)
		len = 7;
	while (*sa)
	{
		if (almost_ordered(*sa) || sort_num(sa, sb, ret, len))
		{
			rotate_cor(ret, sa, sb, 0);
			mergetwo(sa, sb, ret);
			rotate_cor(ret, sa, sb, 0);
			break ;
		}
		struct_a_moves(*sa);
		struct_b_moves(*sa, *sb);
		move_direction(*sa);
		insertbest(sa, sb, ret);
	}
}
