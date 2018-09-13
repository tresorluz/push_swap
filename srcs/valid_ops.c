/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:57:58 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:44:21 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			not_get_op(t_op *list, char *line)
{
	if (!(ft_strcmp(line, "sa")))
		list->fp = &sa_cmd;
	else if (!(ft_strcmp(line, "sb")))
		list->fp = &sb_cmd;
	else if (!(ft_strcmp(line, "ss")))
		list->fp = &ss_cmd;
	else if (!(ft_strcmp(line, "pa")))
		list->fp = &fpa;
	else if (!(ft_strcmp(line, "pb")))
		list->fp = &fpb;
	else if (!(ft_strcmp(line, "ra")))
		list->fp = &ra_cmd;
	else if (!(ft_strcmp(line, "rb")))
		list->fp = &rb_cmd;
	else if (!(ft_strcmp(line, "rr")))
		list->fp = &rr_cmd;
	else if (!(ft_strcmp(line, "rra")))
		list->fp = &rra_cmd;
	else if (!(ft_strcmp(line, "rrb")))
		list->fp = &rrb_cmd;
	else if (!(ft_strcmp(line, "rrr")))
		list->fp = &rrr_cmd;
	else
		return (1);
	return (0);
}

static int	op_num(t_op *list, char *line)
{
	if (!(ft_strcmp(line, "sa")))
		list->op = sa;
	else if (!(ft_strcmp(line, "sb")))
		list->op = sb;
	else if (!(ft_strcmp(line, "ss")))
		list->op = ss;
	else if (!(ft_strcmp(line, "pa")))
		list->op = pa;
	else if (!(ft_strcmp(line, "pb")))
		list->op = pb;
	else if (!(ft_strcmp(line, "ra")))
		list->op = ra;
	else if (!(ft_strcmp(line, "rb")))
		list->op = rb;
	else if (!(ft_strcmp(line, "rr")))
		list->op = rr;
	else if (!(ft_strcmp(line, "rra")))
		list->op = rra;
	else if (!(ft_strcmp(line, "rrb")))
		list->op = rrb;
	else if (!(ft_strcmp(line, "rrr")))
		list->op = rrr;
	else
		return (1);
	return (0);
}

t_op		*get_ops(void)
{
	char	*line;
	t_op	*list;
	t_op	*begin;
	t_op	*prev;

	line = NULL;
	list = init_operation();
	begin = list;
	prev = list;
	get_ops2(line, list, prev);
	return (begin);
}

void		get_ops2(char *line, t_op *list, t_op *prev)
{
	while (get_next_line(0, &line))
	{
		if (not_get_op(list, line))
		{
			if (ft_strequ(line, ""))
			{
				free(line);
				break ;
			}
			write(2, "Error\n", 6);
			exit(1);
		}
		op_num(list, line);
		list->next = init_operation();
		prev = list;
		list = list->next;
		free(line);
	}
	free(list);
	prev->next = NULL;
}
