/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/24 15:08:11 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_argument(t_flags *flags, va_list ap)
{
	char		*str;

	str = NULL;
	if (flags->conversion == 'd' || flags->conversion == 'i')
		str = get_int(flags, ap);
	else if (flags->conversion == 'o' || flags->conversion == 'u' ||
			flags->conversion == 'x' || flags->conversion == 'X' ||
			flags->conversion == 'p')
		str = get_unsigned(flags, ap);
	else if (flags->conversion == 's')
		str = get_string(flags, ap);
	else if (flags->conversion == 'c' || flags->conversion == '%')
		str = get_character(flags, ap);
	else if (flags->conversion == 'f' || flags->conversion == 'F' ||\
			flags->conversion == 'g' || flags->conversion == 'G' ||\
			flags->conversion == 'e' || flags->conversion == 'E')
		get_float_double(flags, ap);
	else
		return (0);
	if (str)
	{
		write(flags->fd, str, flags->field_len);
		free(str);		
	}
	return (1);
}
