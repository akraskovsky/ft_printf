/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_character.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:13:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/20 15:52:35 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*char_to_str(t_flags *flags, char c)
{
	size_t	arg_len;
	size_t	shift;
	char	*str;
	char	fill;

	arg_len = 1;
	if (flags->precision_set && flags->precision < arg_len)
		arg_len = flags->precision;
	flags->field_len = (flags->min_width > arg_len) ?
			flags->min_width : arg_len;
	shift = (flags->left) ? 0 : flags->field_len - arg_len;
	fill = (flags->zero_padding && !flags->left) ? '0' : ' ';
	if ((str = ft_strnewfill(flags->field_len, fill)))
		str[shift] = c;
	return (str);
}

char		*get_character(t_flags *flags, va_list ap)
{
	char	c;

	if (flags->conversion == 'c')
		c = (unsigned char)va_arg(ap, int);
	else
		c = '%';
	return (char_to_str(flags, c));
}
