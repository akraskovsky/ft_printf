/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:58:51 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/27 15:37:30 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int			ft_isspace(char c)
{
	return (c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f' || \
			c == ' ');
}

static int			ft_base(char c, int  base)
{
	char	*str;
	char	*str1;
	int		i;

	str = "0123456789abcdef";
	str1 = "0123456789ABCDEF";
	i = 0;
	while ((str[i] || str1[i]) && i < base)
	{
		if (c == str[i] || c == str1[i])
			return (i);
		i++;
	}
	return (-1);
}

int					ft_atoi_base(const char *str, int str_base)
{
	int			neg;
	int			res;

	res = 0;
	neg = 1;
	while (*str && ft_isspace(*str))
		str++;
	if ( *str == '+' || *str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str && ft_base(*str, str_base) != -1)
	{
		res = (res * str_base) + ft_base(*str, str_base);
		str++;
	}
	return (res * neg);
}
