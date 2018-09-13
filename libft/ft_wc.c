/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluzing <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:53:17 by tluzing           #+#    #+#             */
/*   Updated: 2018/09/04 11:24:48 by tluzing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

int	ft_wc(char *s, char c)
{
	int	i;
	int flag;
	int	words;

	i = 0;
	flag = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != c) && flag == 0)
		{
			flag = 1;
			words += 1;
		}
		else if (s[i] == c)
		{
			flag = 0;
		}
		i++;
	}
	return (words);
}
