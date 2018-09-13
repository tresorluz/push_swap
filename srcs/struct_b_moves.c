/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_b_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:13:49 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/08 10:14:23 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "../libft/libft.h"

static int	struct_b_helpgt(t_stack *sa, t_stack *temp_b)
{
	int i;

	i = 0;
	while (sa->v > temp_b->v)
	{
		i++;
		temp_b = temp_b->next;
	}
	while (sa->v < temp_b->v)
	{
		i++;
		temp_b = temp_b->next;
	}
	return (i);
}

static int	struct_b_helpsmallest(t_stack *temp_b, t_stack *sb)
{
	int i;

	i = 1;
	while (temp_b->v != smallest_int(sb))
	{
		i++;
		temp_b = temp_b->next;
	}
	return (i);
}

static int	struct_b_helplargest(t_stack *temp_b, t_stack *sb)
{
	int i;

	i = 0;
	while (temp_b->v != largest_int(sb))
	{
		i++;
		temp_b = temp_b->next;
	}
	return (i);
}

static int	bstructhelplt(t_stack *temp_b, t_stack *sa)
{
	int i;

	i = 0;
	while (sa->v < temp_b->v)
	{
		i++;
		temp_b = temp_b->next;
	}
	return (i);
}

void		struct_b_moves(t_stack *sa, t_stack *sb)
{
	int		i;
	t_stack *temp_b;

	if (!(sb))
		return ;
	while (sa)
	{
		i = 0;
		temp_b = sb;
		if (sa->v < (get_end(&temp_b)->v) && sa->v > temp_b->v)
			;
		else if (sa->v > largest_int(sb))
			i = struct_b_helplargest(temp_b, sb);
		else if (sa->v < smallest_int(sb))
			i = struct_b_helpsmallest(temp_b, sb);
		else if (sa->v > (get_end(&temp_b)->v) && sa->v > temp_b->v)
			i = struct_b_helpgt(sa, temp_b);
		else
			i = bstructhelplt(temp_b, sa);
		sa->mbf = i;
		sa->mbr = (stack_len(sb)) - i;
		sa = sa->next;
	}
}
