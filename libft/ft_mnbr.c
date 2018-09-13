/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 11:21:58 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/04 11:22:00 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mnbr(char *num, int len, int n)
{
	long	copy;
	int		i;

	i = 0;
	copy = n;
	num[len] = '\0';
	if (copy < 0)
	{
		num[i] = '-';
		i++;
		copy = copy * -1;
	}
	while (copy != 0)
	{
		len--;
		num[len] = ((copy % 10) + '0');
		copy = copy / 10;
	}
}
