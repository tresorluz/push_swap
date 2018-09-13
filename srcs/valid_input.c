/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:58:37 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/07 12:47:57 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int			valid_int(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		if (ps_big_atoi(av[i]) > INT_MAX || ps_big_atoi(av[i]) < INT_MIN)
			return (0);
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				;
			else if (!ft_isdigit(av[i][j]))
			{
				if (!(av[i][j] == '-' && ft_isdigit(av[i][j + 1])))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static void	arg_split(t_stack **stack, char *avin)
{
	int		j;
	char	**temp;

	j = 0;
	temp = ft_strsplit(avin, ' ');
	while (temp[j])
	{
		(*stack)->v = (int)ps_big_atoi(temp[j]);
		if (!temp[j + 1])
			break ;
		(*stack)->next = init_stack();
		((*stack)->next)->prev = (*stack);
		(*stack) = (*stack)->next;
		j++;
	}
	j = 0;
	while (temp[j])
	{
		free(temp[j]);
		j++;
	}
	free(temp);
}

t_stack		*make_stack(char **av)
{
	int		i;
	t_stack *stack;
	t_stack *begin;

	i = 1;
	stack = init_stack();
	begin = stack;
	while (av[i])
	{
		arg_split(&stack, av[i]);
		if (!av[i + 1])
			return (begin);
		stack->next = init_stack();
		(stack->next)->prev = stack;
		stack = stack->next;
		i++;
	}
	return (begin);
}

static int	check_duplicate(t_stack *stack_a)
{
	int		num;
	int		flag;
	t_stack *temp_a;
	t_stack *temp_b;

	temp_a = stack_a;
	while (stack_a)
	{
		num = stack_a->v;
		flag = 0;
		temp_b = temp_a;
		while (temp_b)
		{
			if (temp_b->v == num)
				flag++;
			if (flag > 1)
				return (1);
			temp_b = temp_b->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

t_stack		*valid_input(int ac, char **av, t_stack *stack_a)
{
	char	**temp;

	temp = av;
	if (ac < 2)
		return (NULL);
	if (!(ft_strcmp("-v", temp[1])))
		temp++;
	if (!valid_int(temp))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	stack_a = make_stack(temp);
	if (check_duplicate(stack_a))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (stack_a);
}
