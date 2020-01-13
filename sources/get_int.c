/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/13 19:38:00 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_arg_len(t_flags *flags, long long num)
{
	size_t	len;

	len = 1;
	if (num == 0 && flags->precision == 0 && flags->precision_set)
		len = 0;
	while (num /= 10)
		len++;
	if (flags->precision > len)
		len = flags->precision;
	if (num < 0 || flags->sign || flags->first_space)
		len++;
	if (flags->min_width > len && flags->zero_padding &&
			!flags->left && !flags->precision_set)
		len = flags->min_width;
	return (len);
}

static char		*arg_to_str(t_flags *flags, long long num)
{
	char	*str;
	int		sign;
	size_t	arg_len;
	size_t	shift;


	sign = (num < 0) ? -1 : 1;
	arg_len = get_arg_len(flags, num);
	flags->field_len = (flags->min_width > arg_len) ?
						flags->min_width : arg_len;
	shift = (flags->left) ? 0 : flags->field_len - arg_len;
	if ((str = ft_strnewfill(flags->field_len, ' ')))
	{
		while (arg_len--)
		{
			str[arg_len + shift] = (num % 10 * sign) + '0';
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

char	*get_int(t_flags *flags, va_list ap)
{
	long long	num;

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
	return (arg_to_str(flags, num));
}
