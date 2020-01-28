/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/28 14:06:03 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_arg(t_flags *flags, char *str)
{
	if (str != NULL)
	{
		write(flags->fd, str, flags->field_len);
		free(str);
	}
}

int			get_argument(t_flags *flags, va_list ap)
{
	char		*str;

	str = NULL;
	if (flags->conversion == 'd' || flags->conversion == 'i')
		if (!(str = get_int(flags, ap)))
			return (0);
	if (flags->conversion == 'o' || flags->conversion == 'u' ||
			flags->conversion == 'x' || flags->conversion == 'X' ||
			flags->conversion == 'p')
		if (!(str = get_unsigned(flags, ap)))
			return (0);
	if (flags->conversion == 's')
		if (!(str = get_string(flags, ap)))
			return (0);
	if (flags->conversion == 'c' || flags->conversion == '%')
		if (!(str = get_character(flags, ap)))
			return (0);
	if (flags->conversion == 'f' || flags->conversion == 'F' ||\
			flags->conversion == 'g' || flags->conversion == 'G' ||\
			flags->conversion == 'e' || flags->conversion == 'E')
		get_f_double(flags, ap);
	put_arg(flags, str);
	return (1);
}
