/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/25 19:55:01 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* spcdiouxXf */
int		get_argument(t_flags *flags, char **ptr, va_list ap)
{
	int	num;

	num = 0;
	if (**ptr == 'd' || **ptr == 'i')
	{
		if (flags->mod_char)
			num = (char)va_arg(ap, int);
		else if (flags->mod_char)
			num = (short)va_arg(ap, int);
		else
			num = va_arg(ap, int);
	}
	ft_putnbr(num);
	(*ptr)++;
	return (1);
}
