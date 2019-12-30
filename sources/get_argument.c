/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/27 20:23:01 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	arg_len(t_flags *flags, long long num, int base)
{
	size_t	len;

	len = 1;
	while (num /= base)
		len++;
	return (len);
}

char	*pf_itoa(t_flags *flags, long long num, int base)
{
	char	*str;
	int		len;
	int		strlen;
	int		sign;

	sign = (num < 0) ? 1 : 0;
	len = arg_len(flags, num, 10);
	len = (flags->precision > len) ? flags->precision : len;
	if ()

	if ((str = ft_strnew(len + sign)))
	{
		if (sign)
			*str = '-';
		while (len--)
		{
			if (sign)
				str[len + sign] = (num % 10 * -1) + '0';
			else
				str[len] = (num % 10) + '0';
			num /= 10;
		}
	}
	return (str);
}

/* di ouxXp sc f */
int		get_argument(t_flags *flags, char **ptr, va_list ap)
{
	long long	num;
	char		*str;

	num = 0;
	if (**ptr == 'd' || **ptr == 'i')
	{
		if (flags->mod_char)
			num = (char)va_arg(ap, int);
		else if (flags->mod_short)
			num = (short)va_arg(ap, int);
		else if (flags->mod_long)
			num = va_arg(ap, long);
		else if (flags->mod_long_long)
			num = va_arg(ap, long long);
		else
			num = va_arg(ap, int);
	}
	if (**ptr == 'd' || **ptr == 'i')

//	str = pf_itoa(flags, num);
//	ft_putnbr(num);
	(*ptr)++;
	return (1);
}
