/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:11:41 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:22:13 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_op	*init_operation(void)
{
	t_op *list;

	list = (t_op *)(malloc(sizeof(t_op)));
	list->op = nothing;
	list->fp = NULL;
	list->next = NULL;
	return (list);
}

t_stack	*init_stack(void)
{
	t_stack *stack;

	stack = (t_stack *)(malloc(sizeof(t_stack)));
	stack->prev = NULL;
	stack->next = NULL;
	stack->g = 0;
	stack->maf = 0;
	stack->mar = 0;
	stack->mbf = 0;
	stack->mbr = 0;
	stack->moves = 0;
	stack->dir = 0;
	return (stack);
}

t_out	*outinit(void)
{
	t_out	*outlist;

	outlist = (t_out *)(malloc(sizeof(t_out)));
	outlist->next = NULL;
	outlist->num = NOTHING;
	return (outlist);
}

void	print_cmds(t_optype num)
{
	if (num == sa)
		ft_putstr_fd("sa\n", 2);
	else if (num == sb)
		ft_putstr_fd("sb\n", 2);
	else if (num == ss)
		ft_putstr_fd("ss\n", 2);
	else if (num == pa)
		ft_putstr_fd("pa\n", 2);
	else if (num == pb)
		ft_putstr_fd("pb\n", 2);
	else if (num == ra)
		ft_putstr_fd("ra\n", 2);
	else if (num == rb)
		ft_putstr_fd("rb\n", 2);
	else if (num == rr)
		ft_putstr_fd("rr\n", 2);
	else if (num == rra)
		ft_putstr_fd("rra\n", 2);
	else if (num == rrb)
		ft_putstr_fd("rrb\n", 2);
	else if (num == rrr)
		ft_putstr_fd("rrr\n", 2);
}

void	print_cmds2(t_onum num)
{
	if (num == SA)
		ft_putstr("sa\n");
	else if (num == SB)
		ft_putstr("sb\n");
	else if (num == SS)
		ft_putstr("ss\n");
	else if (num == PA)
		ft_putstr("pa\n");
	else if (num == PB)
		ft_putstr("pb\n");
	else if (num == RA)
		ft_putstr("ra\n");
	else if (num == RB)
		ft_putstr("rb\n");
	else if (num == RR)
		ft_putstr("rr\n");
	else if (num == RRA)
		ft_putstr("rra\n");
	else if (num == RRB)
		ft_putstr("rrb\n");
	else if (num == RRR)
		ft_putstr("rrr\n");
	else if (num == NOTHING)
		ft_putstr("\n");
}
