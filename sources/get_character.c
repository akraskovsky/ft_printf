/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_character.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:13:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/29 13:02:58 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//static char	*char_to_str(t_flags *flags, char c)
int		get_character(t_flags *flags, va_list ap)

{
	char	c;
	size_t	arg_len;
	size_t	shift;
	char	fill;

	if (flags->conversion == 'c')
		c = (unsigned char)va_arg(ap, int);
	else
		c = '%';
	arg_len = 1;
	flags->field_len = (flags->min_width > arg_len) ?
			flags->min_width : arg_len;
	shift = (flags->left) ? 0 : flags->field_len - arg_len;
	fill = (flags->zero_padding && !flags->left) ? '0' : ' ';
	if ((flags->arg = ft_strnewfill(flags->field_len, fill)))
		flags->arg[shift] = c;
	return ((flags->arg) ? 1 : 0);
}

/*
char		*get_character(t_flags *flags, va_list ap)
{
	char	c;

	if (flags->conversion == 'c')
		c = (unsigned char)va_arg(ap, int);
	else
		c = '%';
	return (char_to_str(flags, c));
}
*/
