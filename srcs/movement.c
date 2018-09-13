/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:13:22 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:23:26 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		rotate_cor(t_out *ret, t_stack **sa, t_stack **sb, int descending)
{
	int temp;

	temp = 0;
	if (descending)
	{
		temp = largest_int(*sb);
		if (wheredestj(*sb, temp) >= 0)
			while ((*sb)->v != temp)
				updatestack(ret, RB, sa, sb);
		else
			while ((*sb)->v != temp)
				updatestack(ret, RRB, sa, sb);
	}
	else
	{
		temp = smallest_int(*sa);
		if (wheredestj(*sa, temp) >= 0)
			while ((*sa)->v != temp)
				updatestack(ret, RA, sa, sb);
		else
			while ((*sa)->v != temp)
				updatestack(ret, RRA, sa, sb);
	}
}

void		struct_a_moves(t_stack *sa)
{
	int		i;
	t_stack *temp_a2;

	i = 0;
	temp_a2 = sa;
	while (sa)
	{
		sa->maf = i;
		sa = sa->next;
		i++;
	}
	temp_a2->mar = 0;
	temp_a2 = temp_a2->next;
	i--;
	while (temp_a2)
	{
		temp_a2->mar = i;
		temp_a2 = temp_a2->next;
		i--;
	}
}

static void	move_direction_help(t_stack *sa, int *ar)
{
	if (ar[0] <= ar[1] && ar[0] <= ar[2] && ar[0] <= ar[3])
	{
		sa->moves = ar[0];
		sa->dir = 1;
	}
	else if (ar[1] <= ar[0] && ar[1] <= ar[2] && ar[1] <= ar[3])
	{
		sa->moves = ar[1];
		sa->dir = 2;
	}
	else if (ar[2] <= ar[0] && ar[2] <= ar[1] && ar[2] <= ar[3])
	{
		sa->moves = ar[2];
		sa->dir = 3;
	}
	else if (ar[3] <= ar[1] && ar[3] <= ar[0] && ar[3] <= ar[2])
	{
		sa->moves = ar[3];
		sa->dir = 4;
	}
}

void		move_direction(t_stack *sa)
{
	int *ar;

	ar = (int *)malloc(sizeof(int) * 4);
	while (sa)
	{
		ar[0] = ((sa->maf > sa->mbf) ? sa->maf : sa->mbf);
		ar[1] = ((sa->mar > sa->mbr) ? sa->mar : sa->mbr);
		ar[2] = sa->maf + sa->mbr;
		ar[3] = sa->mar + sa->mbf;
		move_direction_help(sa, ar);
		sa = sa->next;
	}
	free(ar);
}
