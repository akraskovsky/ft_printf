/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:54:12 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/26 20:55:32 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_itoa(t_flags *flags, long long num)
{
	char	str[20];
	int		len;
	int		sign;

	len = 1;
	while ((num /= 10))
		len++;

}
/* spcdiouxXf */
int		get_argument(t_flags *flags, char **ptr, va_list ap)
{
	long long	num;
	char		*str;

	num = 0;
	if (**ptr == 'd' || **ptr == 'i')
	{
		if (flags->mod_char)
			num = (char)va_arg(ap, int);
		else if (flags->mod_short)
			num = (short)va_arg(ap, int);
		else if (flags->mod_long)
			num = va_arg(ap, long);
		else if (flags->mod_long_long)
			num = va_arg(ap, long long);
		else
			num = va_arg(ap, int);
	}
	str = pf_itoa(flags, num)
//	ft_putnbr(num);
	(*ptr)++;
	return (1);
}
