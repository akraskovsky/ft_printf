/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/30 17:13:46 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* di ouxXp sc f */
int		get_argument(t_flags *flags, char **ptr, va_list ap)
{
	long long	num;
//	char		*str;

	num = 0;
	if (**ptr == 'd' || **ptr == 'i')
		get_int(flags, ap);
/*	else if (**ptr == 'o' || **ptr == 'u' || **ptr == 'x' || **ptr == 'X'
				|| **ptr == 'p')
		get_unsigned(flags, ap);
	else if (**ptr == 's' || **ptr == 'c')
		get_string(flags, ap);
	else if (**ptr == 'f')
		get_float(flags, ap);*/
	else
	{
		write(1, "\nBad conversion!\n", 17);
		return (0);
	}
	(*ptr)++;
	return (1);
}
