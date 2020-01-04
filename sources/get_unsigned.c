/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/04 20:32:32 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	arg_len(t_flags *flags, unsigned long long num)
{
	int	len;

	len = 1;
	if (num == 0 && flags->precision == 0 && flags->precision_set)
		return (0);
	while (num /= 10)
		len++;
	if (flags->precision > len)
		len = flags->precision;
	if (flags->alt_out && (flags->conversion == 'o'))
		len++;
	if (flags->alt_out &&
			(flags->conversion == 'x' || flags->conversion == 'X'))
		len += 2;
	return (len);
}

static int		pf_base(char c)
{
	if (c == 'o')
		return (8);
	if (c == 'u')
		return (10);
	return (16);
}

static char		*pf_itoa_u(t_flags *flags, unsigned long long num)
{
	char	*str;
	int		strlen;
	int		base;

	strlen = arg_len(flags, num);
	base = pf_base(flags->conversion);
	if ((str = ft_strnew(strlen)))
	{
		while (strlen--)
		{
			str[strlen] = (num % base) + 48;
			if (str[strlen] > 57 && flags->conversion == 'X')
				str[strlen] += 7;
			if (str[strlen] > 57 && flags->conversion == 'x')
				str[strlen] += 39;
			num /= base;
		}
		if (flags->alt_out && base != 10 && flags->conversion != 'p')
			*str = '0';
		if (flags->alt_out && base == 16 && flags->conversion != 'p')
			*(str + 1) = flags->conversion;
	}
	return (str);
}

/*  conversions ouxXp  */
char			*get_unsigned(t_flags *flags, va_list ap)
{
	unsigned long long	num;
	char				*str;

	num = 0;
	if (flags->mod_char)
		num = (unsigned char)va_arg(ap, unsigned int);
	else if (flags->mod_short)
		num = (unsigned short)va_arg(ap, unsigned int);
	else if (flags->mod_long)
		num = va_arg(ap, unsigned long);
	else if (flags->mod_long_long)
		num = va_arg(ap, unsigned long long);
	else
		num = (unsigned int)va_arg(ap, unsigned int);
	str = pf_itoa_u(flags, num);
	return (str);
}
