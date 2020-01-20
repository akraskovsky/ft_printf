/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:03:53 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/19 19:11:39 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_long_double(long double i, t_flags *flags)
{
	char				*all;
	char				*res;
	int					exponent;
	int					sign;

	res = NULL;
	all = ft_ld_helper(&sign, i);//ld -> in massiv char throw union
	if (i != i || i == +1.0 / 0.0 || i == -1.0 / 0.0)
	{
		res = put_nan_inf(i, *flags);//f_nan_inf.c NAN INF
		exponent = filler_nan(res, *flags, sign, all);//f_nan_inf.c
	}
	else
	{
		res = ld_helper(i, all, res, flags);//преобразованное число из массива char 
		//с двоичным представлением в массив char с десятичным представлением числа + с точкой
		exponent = flag_f(res, *flags, sign);
	}
	free(res);
	return (exponent);
	return (1);
}

int		ft_printf_float_double(double i, t_flags *flags)//float -> long double
{
	double	a;
	int		ret;

	a = (double)i;
	ret = ft_printf_long_double(a, flags);
	return (ret);
}

char	*ft_ld_helper(int *sign, long double i)//long double -> massiv char throw union
{
	union u_d_double	u_double;
	char				*all;

	u_double.d = i;
	all = get_double_binary(u_double);//f_get_binary.c
	*sign = all[0] - '0';
	return (all);
}

char	*ld_helper(long double i, char *all, char *res, t_flags *flags)
{
	int exponent;

	if (i == 0.0 || i == -0.0)
		res = ft_strdup("00.0");
	else
	{
		exponent = get_exp(all);//f_get_binary.c экспонента
		if (i != 2.0 && i != -2.0)
			res = f_dealer(exponent, all, res, i);//d_helper2.c мантисса
		else
			res = ft_strdup("02.0");
	}
	res = bank_rounding(res, flags->precision);
	if (flags->mod_long_double == 'G' || flags->mod_long_double == 'g' \
        || flags->mod_long_double == 55)
		res = cut_z(res);
	return (res);
}