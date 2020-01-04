/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:49:52 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/04 16:23:50 by fprovolo         ###   ########.fr       */
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
	flags->len = 0;
	return ;
}

int     ft_printf(char *str, ...)
{
	va_list	ap;
	t_flags	flags;
//	char	buff[BUFF_SIZE];
	char	*ptr;

	ptr = str;
	va_start(ap, str);
	while (*ptr != '\0')
		if (*ptr == '%')
		{
			if (!(parse_format(&ptr, &flags, ap)))
				return (-1);
		}
		else
		{
			write(1, ptr, 1);
			ptr++;
		} 
	va_end(ap);
	print_flags(&flags);
	return (0);
}