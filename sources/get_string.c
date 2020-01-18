/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:13:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/18 14:59:12 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_to_str(t_flags *flags, char *string)
{
	size_t	arg_len;
	size_t	shift;
	char	*str;
	char	fill;

	if (string == NULL)
		arg_len = 6;
	else
		arg_len = ft_strlen(string);
	if (flags->precision_set && flags->precision < arg_len)
		arg_len = flags->precision;
	flags->field_len = (flags->min_width > arg_len) ?
			flags->min_width : arg_len;
	shift = (flags->left) ? 0 : flags->field_len - arg_len;
	fill = (flags->zero_padding && !flags->left) ? '0' : ' ';
	if ((str = ft_strnewfill(flags->field_len, fill)))
	{
		if (string != NULL)
			ft_memcpy(str + shift, string, arg_len);
		else
			ft_memcpy(str + shift, "(null)", arg_len);
	}
	return (str);
}

char		*get_string(t_flags *flags, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	return (str_to_str(flags, str));
}
