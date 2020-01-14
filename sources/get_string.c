/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:13:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/14 15:46:06 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_arg_len(t_flags *flags, char *string)
{
	size_t	len;

	if (flags->conversion == 's')
	{
		len = ft_strlen(string);
		if (flags->precision_set && flags->precision < len)
			len = flags->precision;
	}
	else
		len = 1;
	return (len);
}

static char		*str_to_str(t_flags *flags, char *string, char c)
{
	size_t	arg_len;
	size_t	shift;
	char	*str;
	char	fill;

	arg_len = get_arg_len(flags, string);
	flags->field_len = (flags->min_width > arg_len) ?
			flags->min_width : arg_len;
	shift = (flags->left) ? 0 : flags->field_len - arg_len;
	fill = (flags->zero_padding && !flags->left) ? '0' : ' ';
	if ((str = ft_strnewfill(flags->field_len, fill)))
	{
		if (flags->conversion == 'c')
			str[shift] = c;
		else
			ft_memcpy(str + shift, string, arg_len);
	}
	return (str);
}

/*  conversions sc  */
char		*get_string(t_flags *flags, va_list ap)
{
	char	*str;
	char	c;

	str = NULL;
	c = 0;
	if (flags->conversion == 's')
		str = va_arg(ap, char *);
	else if (flags->conversion == 'c')
		c = (unsigned char)va_arg(ap, int);
	return (str_to_str(flags, str, c));
}