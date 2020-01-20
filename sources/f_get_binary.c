/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_get_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:54:44 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/20 14:49:32 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_double_binary(union u_d_double u_double)//massiv char trow union
{
	char	*all;
	int		count;
	int		shift;
	int		block;

	all = ft_strnew(81);
	count = 0;
	shift = 7;
	block = 9;
	while (count < 80)
	{
		all[count++] = (char)((u_double.c[block] >> shift--) & 1) + '0';
		if (shift == -1)
		{
			shift = 7;
			block--;
		}
	}
	return (all);
}

char	*get_mant(char *all)//берем мантиссу
{
	int		i;
	char	*str_man;//массив для байт мантиссы

	str_man = ft_strnew(65);
	i = 0;
	while (i < 64)
	{
		str_man[i] = all[i + 17];
		i++;
	}
	free(all);
	str_man = mant_from_2_to_10(str_man);//f_tools.c
	str_man[0] = '1';
	return (str_man);
}

char	*mant_multby2(int exponent, char *str_man)
{
	char	*mant;
	int		count;

	mant = ft_strnew(5002);//пустой массив для вычислений размеров
	count = 0;
	while (count <= 5000)
		mant[count++] = '0';
	if (exponent > 0)
		mant = mult2_mant_exppositive(mant, str_man, exponent);//f_tools_mant+мантисса в степени эксп.
	else if (exponent < 0)
		mant = mult2_mant_expnegative(mant, str_man, exponent);//f_tools_mant-мантисса в степени эксп.
	else if (exponent == 0)
	{
		free(mant);
		mant = str_man;
		mant[1] = '.';
	}
	if (mant != str_man)
		free(str_man);
	return (mant);
}

int		get_exp(char *all)//вычисляем экспоненту
{
	char	*str_exp;//байты экспоненты
	int		i;
	int		exponent;

	str_exp = ft_strnew(16);
	i = 0;
	while (i < 15)
	{
		str_exp[i] = all[i + 1];//байты ответственные за экспоненту
		i++;
	}
	exponent = ft_atoi_base(str_exp, 2);//десятичное число
	free(str_exp);
	exponent -= 16383;
	return (exponent);
}

int		find_e(char *str, double num)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (num == 0.0 || num == -0.0)
		return (0);
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (i > 1 && str[1] != '0' && ft_strchr(str, '.') != NULL)
		return (i - 2);
	else if (i == (int)ft_strlen(str))
		return (find_e_helper(i, j, str));
	else
	{
		i++;
		j = -1;
		while (str[i] == '0' && str[i] != '\0')
		{
			j--;
			i++;
		}
		return (j);
	}
}

