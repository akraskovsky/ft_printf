/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:49:52 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/14 13:41:53 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->alt_out = 0;
	flags->zero_padding = 0;
	flags->left = 0;
	flags->first_space = 0;
	flags->sign = 0;
	flags->thousands = 0;
	flags->min_width = 0;
	flags->precision = 0;
	flags->precision_set = 0;
	flags->mod_char = 0;
	flags->mod_short = 0;
	flags->mod_long = 0;
	flags->mod_long_long = 0;
	flags->mod_long_double = 0;
	flags->conversion = 0;
	flags->field_len = 0;
	return ;
}

int     ft_printf(char *str, ...)
{
	va_list	ap;
	t_flags	flags;
	int		length;
	int		i;

	length = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
		if (str[i] != '%')
			i++;
		else
		{
			write(1, str, i);
			length += i;
			str += i;
			i = 0;
			if (!(parse_format(&str, &flags, ap)))
				return (-1);
			length += flags.field_len;
		}
	write(1, str, i);
	length += i;
	va_end(ap);
	return (length);
}