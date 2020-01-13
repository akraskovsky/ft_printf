/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/13 17:50:35 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* di ouxXp sc f */
int		get_argument(t_flags *flags, va_list ap)
{
	long long	num;
	char		*str;

	num = 0;
	if (flags->conversion == 'd' || flags->conversion == 'i')
		str = get_int(flags, ap);
	else if (flags->conversion == 'o' || flags->conversion == 'u' ||
			flags->conversion == 'x' || flags->conversion == 'X' ||
			flags->conversion == 'p')
		str = get_unsigned(flags, ap);
/*	else if (**ptr == 's' || **ptr == 'c')
		get_string(flags, ap);
	else if (**ptr == 'f')
		get_float(flags, ap);*/
	else
	{
		write(1, "\nBad conversion!\n", 17);
		return (0);
	}
	write(1, str, flags->field_len);
	free(str);
	return (1);
}
