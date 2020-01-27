/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:03:53 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/27 16:40:51 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_f_double(t_flags *flags, va_list ap)
{
	double				num;
	long double			i;
	
	i = 0;
	num = 0;
	if ((flags->conversion == 'f' || flags->conversion == 'F') && !(flags->mod_long_double))
	{
		num = va_arg(ap, double);
		flags->field_len = (ft_printf_f_double(num, flags));
	}		
	else if ((flags->conversion == 'f' || flags->conversion == 'F') \
			&& flags->mod_long_double) 
	{
		i = va_arg(ap, long double);
		flags->field_len = (ft_printf_l_double(i, flags));
	}
}

int		ft_printf_l_double(long double i, t_flags *flags)
{
	char				*all;
	char				*res;
	int					exponent;
	int					sign;

	res = NULL;
	all = ft_char_from_union(&sign, i);//ld -> in massiv char throw union
	if (i != i || i == +1.0 / 0.0 || i == -1.0 / 0.0)
	{
		res = put_nan_inf(i, *flags);//f_nan_inf.c NAN INF
		exponent = filler_nan(res, *flags, sign, all);//f_nan_inf.c
	}
	else
	{
		res = ld_char_ten(i, all, res, flags);//преобразованное число из массива char 
		//с двоичным представлением в массив char с десятичным представлением числа + с точкой
		exponent = flag_f(res, *flags, sign);
	}
	free(res);
	return (exponent);
	return (1);
}

int		ft_printf_f_double(double i, t_flags *flags)//float -> long double
{
	double	k;
	int		length;

	k = (double)i;
	length = ft_printf_l_double(k, flags);
	return (length);
}

char	*ft_char_from_union(int *sign, long double i)//long double -> massiv char throw union
{
	union u_a_double	u_double;
	char				*all;

	u_double.a = i;
	all = get_double_bin(u_double);//f_get_binary.c
	*sign = all[0] - '0';
	return (all);
}

char	*ld_char_ten(long double i, char *all, char *res, t_flags *flags)
{
	int exponent;

	if (i == 0.0 || i == -0.0)
		res = ft_strdup("00.0");
	else
	{
		exponent = ft_exponent(all);//f_get_binary.c экспонента
		if (i != 2.0 && i != -2.0)
			res = f_dealer(exponent, all, res, i);//f_dealer.c мантисса
		else
			res = ft_strdup("02.0");
	}
	res = bank_rounding(res, flags->precision, flags->precision_set);//банковское округление
	if (flags->conversion == 'G' || flags->conversion == 'g' \
        || flags->conversion == 55)
		res = cut_z(res);// работа с флагами
	return (res);
}