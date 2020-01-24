/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_long_eg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:19:07 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/20 17:20:01 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_le_helper1(long double i, char *res, char *all)
{
	int	ex;

	if (i == 0.0 || i == -0.0)
	{
		res = ft_strdup("00.0");
		ex = 0;
	}
	else
	{
		ex = get_exp(all);
		if (i != 2.0 && i != -2.0)
			res = f_dealer(ex, all, res, i);
		else
			res = ft_strdup("02.0");
	}
	return (res);
}

int		ft_le(long double i, struct s_tfs data)
{
	char				*all;
	char				*res;
	int					ex;
	int					sign;

	all = ft_e_helper(&sign, i);
	res = NULL;
	if (i != i || i == +1.0L / 0.0L || i == -1.0L / 0.0L)
	{
		res = put_nan_inf(i, data);
		ex = filler_nan(res, data, sign, all);
	}
	else
	{
		res = ft_le_helper1(i, res, all);
		ex = find_e(res, i);
		if (i != -0.0L || i != 0.0L)
			res = normalize(res);
		res = ft_e_helper2(i, res, data.precision);
		if (data.t == 'G' || data.t == 'g')
			res = cut_z(res);
		ex = flag_e(res, ex, data, sign);
	}
	free(res);
	return (ex);
}

int		ft_e(double i, struct s_tfs data)
{
	char				*all;
	char				*res;
	int					ex;
	int					sign;

	all = ft_e_helper(&sign, i);
	res = NULL;
	if (i != i || i == +1.0 / 0.0 || i == -1.0 / 0.0)
	{
		res = put_nan_inf(i, data);
		ex = filler_nan(res, data, sign, all);
	}
	else
	{
		res = ft_e_helper1(i, res, all);
		ex = find_e(res, i);
		if (i != -0.0 || i != 0.0)
			res = normalize(res);
		res = ft_e_helper2(i, res, data.precision);
		if (data.t == 'G' || data.t == 'g')
			res = cut_z(res);
		ex = flag_e(res, ex, data, sign);
	}
	free(res);
	return (ex);
}

int		ft_get_exp_for_le(long double i)
{
	int					ex;
	union u_d_double	u_double;
	char				*all;
	char				*res;

	u_double.d = i;
	all = get_double_binary(u_double);
	{
		ex = get_exp(all);
		if (i != 2.0 && i != -2.0)
		{
			res = mant_multby2(ex, get_mant(all));
			res = cut_zeros_before(res);
		}
		else
			res = ft_strdup("02.0");
	}
	ex = find_e(res, i);
	free(res);
	return (ex);
}
