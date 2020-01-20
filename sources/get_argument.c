/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/20 16:30:09 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_argument(t_flags *flags, char **ptr, va_list ap)
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
	else
		return (0);
	if (str)
	{
		write(1, str, flags->field_len);
		free(str);		
	}
	return (1);
}
