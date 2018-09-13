/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:14:12 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:18:53 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "../libft/libft.h"

typedef	enum		e_optype
{
	sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr, nothing
}					t_optype;

typedef enum		e_onum
{
	SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR, NOTHING
}					t_onum;

typedef struct		s_stack
{
	int				v;
	struct s_stack	*prev;
	struct s_stack	*next;
	int				g;
	int				maf;
	int				mar;
	int				mbf;
	int				mbr;
	int				moves;
	int				dir;
}					t_stack;

typedef struct		s_op
{
	t_optype		op;
	void			(*fp)(t_stack **stack_a, t_stack **stack_b);
	struct s_op		*next;
}					t_op;

typedef struct		s_out
{
	t_onum			num;
	struct s_out	*next;
}					t_out;

void				debug_pstacks(t_stack *stack_a, t_stack *stack_b);
int					debug_ops(t_op *begin);
int					largest_int(t_stack *sb);
int					wheredest(t_stack *sb);
int					wheredestj(t_stack *sb, int j);
int					smallest_int(t_stack *sb);
void				struct_b_moves(t_stack *sa, t_stack *sb);
void				move_direction(t_stack *sa);
void				struct_a_moves(t_stack *sa);
void				rotate_cor(t_out *ret, t_stack **sa, t_stack **sb,
					int descending);
void				prepoprot(t_stack *target, t_stack **sa, t_stack **sb,
					t_out *ret);
void				sort_algo(t_stack **sa, t_stack **sb, t_out *ret);
t_op				*init_operation();
t_stack				*init_stack();
t_op				*get_ops();
int					valid_int(char **av);
t_stack				*make_stack(char **av);
t_stack				*valid_input(int ac, char **av, t_stack *stack_a);
int					not_get_op(t_op *list, char *line);
void				process_op(t_stack **stack_a, t_stack **stack_b,
					t_op *list);
int					is_rev_ordered(t_stack *stack_a, t_stack *stack_b);
int					rev_ordered(t_stack *stack_b);
int					ordered(t_stack *stack_b);
int					almost_ordered(t_stack *stack_b);
int					almost_ordered2(t_stack *stack_b, int temp, int temp2);
t_out				*outinit();
int					stack_len(t_stack *stack);
t_stack				*get_end(t_stack **stack);
int					getminrun(t_stack *stack_a);
void				updatestack(t_out *ret, t_onum op, t_stack **sa,
					t_stack **sb);
void				updatestack_rev(t_out *ret, t_onum op, t_stack **sa,
					t_stack **sb);
void				ret_printing(t_out *ret);
int					ret_number(t_out *ret);
void				printoutlist(t_out *outlist);
void				print_cmds(t_optype num);
void				print_cmds2(t_onum num);
void				do_op(t_onum num, t_stack **sa, t_stack **sb);
void				do_op_rev(t_onum num, t_stack **sa, t_stack **sb);
void				get_ops2(char *line, t_op *list, t_op *prev);
void				sa_cmd(t_stack **stack_a, t_stack **stack_b);
void				sb_cmd(t_stack **stack_a, t_stack **stack_b);
void				fpa(t_stack **stack_a, t_stack **stack_b);
void				fpb(t_stack **stack_a, t_stack **stack_b);
void				ss_cmd(t_stack **stack_a, t_stack **stack_b);
void				ra_cmd(t_stack **stack_a, t_stack **stack_b);
void				rb_cmd(t_stack **stack_a, t_stack **stack_b);
void				rr_cmd(t_stack **stack_a, t_stack **stack_b);
void				rra_cmd(t_stack **stack_a, t_stack **stack_b);
void				rrb_cmd(t_stack **stack_a, t_stack **stack_b);
void				rrr_cmd(t_stack **stack_a, t_stack **stack_b);
#endif
