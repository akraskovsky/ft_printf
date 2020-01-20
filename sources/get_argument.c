/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/20 15:10:58 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_argument(t_flags *flags, va_list ap)
{
	char	str[20];
	int		len;
	int		sign;

	len = 1;
	while ((num /= 10))
		len++;

}
/* spcdiouxXf */
int		get_argument(t_flags *flags, char **ptr, va_list ap)
{
	long long	num;
	char		*str;

	str = NULL;
	if (flags->conversion == 'd' || flags->conversion == 'i')
		str = get_int(flags, ap);
	else if (flags->conversion == 'o' || flags->conversion == 'u' ||
			flags->conversion == 'x' || flags->conversion == 'X' ||
			flags->conversion == 'p')
		str = get_unsigned(flags, ap);
	else if (flags->conversion == 's')
		str = get_string(flags, ap);
	else if (flags->conversion == 'c' || flags->conversion == '%')
		str = get_character(flags, ap);
	else
		return (0);
	if (str)
	{
		if (flags->)
	}
	str = pf_itoa(flags, num)
//	ft_putnbr(num);
	(*ptr)++;
	return (1);
}
