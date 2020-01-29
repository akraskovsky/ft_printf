/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/29 13:02:58 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_argument(t_flags *flags, va_list ap)
{
	int			ret;

	if (flags->conversion == 'd' || flags->conversion == 'i')
		ret = get_int(flags, ap);
	if (flags->conversion == 'o' || flags->conversion == 'u' ||
			flags->conversion == 'x' || flags->conversion == 'X' ||
			flags->conversion == 'p')
		ret = get_unsigned(flags, ap);
	if (flags->conversion == 's')
		ret = get_string(flags, ap);
	if (flags->conversion == 'c' || flags->conversion == '%')
		ret = get_character(flags, ap);
	if (flags->conversion == 'f' || flags->conversion == 'F' ||\
			flags->conversion == 'g' || flags->conversion == 'G' ||\
			flags->conversion == 'e' || flags->conversion == 'E')
		get_f_double(flags, ap);
	if (ret && flags->arg != NULL)
	{
		write(flags->fd, flags->arg, flags->field_len);
		free(flags->arg);
	}
	return (ret);
}
