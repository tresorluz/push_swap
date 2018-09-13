/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstructhelp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:48:43 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:22:47 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_op(t_onum num, t_stack **sa, t_stack **sb)
{
	if (num == SA)
		sa_cmd(sa, sb);
	else if (num == SB)
		sb_cmd(sa, sb);
	else if (num == SS)
		ss_cmd(sa, sb);
	else if (num == PA)
		fpa(sa, sb);
	else if (num == PB)
		fpb(sa, sb);
	else if (num == RA)
		ra_cmd(sa, sb);
	else if (num == RB)
		rb_cmd(sa, sb);
	else if (num == RR)
		rr_cmd(sa, sb);
	else if (num == RRA)
		rra_cmd(sa, sb);
	else if (num == RRB)
		rrb_cmd(sa, sb);
	else if (num == RRR)
		rrr_cmd(sa, sb);
}

void	do_op_rev(t_onum num, t_stack **sa, t_stack **sb)
{
	if (num == SA)
		sb_cmd(sa, sb);
	else if (num == SB)
		sa_cmd(sa, sb);
	else if (num == SS)
		ss_cmd(sa, sb);
	else if (num == PA)
		fpb(sa, sb);
	else if (num == PB)
		fpa(sa, sb);
	else if (num == RA)
		rb_cmd(sa, sb);
	else if (num == RB)
		ra_cmd(sa, sb);
	else if (num == RR)
		rr_cmd(sa, sb);
	else if (num == RRA)
		rrb_cmd(sa, sb);
	else if (num == RRB)
		rra_cmd(sa, sb);
	else if (num == RRR)
		rrr_cmd(sa, sb);
}
