/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ret_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 10:15:16 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/08 10:15:24 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		largest_int(t_stack *sb)
{
	int		largest;
	t_stack	*temp;

	temp = sb;
	largest = temp->v;
	while (temp)
	{
		if (largest < temp->v)
			largest = temp->v;
		temp = temp->next;
	}
	return (largest);
}

int		wheredest(t_stack *sb)
{
	int		largest;
	t_stack	*temp;
	int		loc;
	int		i;

	temp = sb;
	largest = temp->v;
	loc = 0;
	i = 0;
	while (temp)
	{
		i++;
		if (largest < temp->v)
		{
			largest = temp->v;
			loc = i;
		}
		temp = temp->next;
	}
	return (loc < (i / 2) ? loc : (((i + 1) - loc) * -1));
}

int		wheredestj(t_stack *sb, int j)
{
	int		goal;
	t_stack	*temp;
	int		loc;
	int		i;

	temp = sb;
	goal = j;
	loc = 0;
	i = 0;
	while (temp)
	{
		if (goal == temp->v)
		{
			loc = i;
		}
		temp = temp->next;
		i++;
	}
	return (loc <= (i / 2) ? 1 : -1);
}
