/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/30 17:53:21 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	arg_len(t_flags *flags, long long num)
{
	int	len;

	len = 1;
	if (num == 0 && flags->precision == 0 && flags->precision_set)
		len = 0;
	while (num /= 10)
		len++;
	if (flags->precision > len)
		len = flags->precision;
	if (num < 0 || flags->sign || flags->first_space)
		len++;
	return (len);
}

char	*pf_itoa(t_flags *flags, long long num)
{
	char	*str;
	int		sign;
	int		strlen;

	sign = (num < 0) ? -1 : 1;
	strlen = arg_len(flags, num);
	if ((str = ft_strnew(strlen)))
	{
		while (strlen--)
		{
			str[strlen] = (num % 10 * sign) + '0';
			num /= 10;
		}
		if (sign < 0)
			*str = '-';
		else if (flags->sign)
			*str = '+';
		else if (flags->first_space)
			*str = ' ';
	}
	return (str);
}

int		get_int(t_flags *flags, va_list ap)
{
	long long	num;
	char		*str;

	num = 0;
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
	str = pf_itoa(flags, num);
	ft_putstr(str);
	return (1);
}
