/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmalik <jmalik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:27:58 by jmalik            #+#    #+#             */
/*   Updated: 2020/01/22 16:40:21 by jmalik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_f(char *res, t_flags flags, int sign)
{
	int	len;
	int	len_fill;
	int	i_width;

	len = ft_strlen(res);
	len_fill = 0;
	if (data.width == -1)
		i_width = 0;
	else
		i_width = data.width;
	if (sign == 1 || data.space == 1 || data.plus == 1)
		len++;
	if (data.grid == 1 && ft_strchr(res, '.') == NULL)
		len++;
	if (data.zero == 1 && data.minus == -1)
		filler_f(res, width(i_width - len, '0'), data, sign);
	else
		filler_f(res, width(i_width - len, ' '), data, sign);
	if (len_fill <= i_width - len)
		len_fill = i_width - len;
	return (len + len_fill);
}

int		flag_e_helper1(int i_width, int len, int *add)
{
	if (0 < i_width - len)
		len = len + (i_width - len);
	free(add);
	return (len);
}

int		flag_e(char *res, int ex, struct s_tfs data, int sign)
{
	int	len;
	int	i_width;
	int *add;

	add = (int *)malloc(2);
	add[0] = ex;
	add[1] = sign;
	len = ft_strlen(res);
	if (data.width == -1)
		i_width = 0;
	else
		i_width = data.width;
	if (sign == 1 || data.space == 1 || data.plus == 1)
		len++;
	if (data.grid == 1 && ft_strchr(res, '.') == NULL)
		len++;
	if (add[0] > 99 || add[0] < -99)
		len = len + 5;
	else
		len = len + 4;
	if (data.zero == 1)
		filler(res, width(i_width - len, '0'), data, add);
	else
		filler(res, width(i_width - len, ' '), data, add);
	return (flag_e_helper1(i_width, len, add));
}

char	*width(int len, char c)
{
	char	*res;
	int		i;

	if (len <= 0)
		return (NULL);
	res = ft_strnew(len + 1);
	i = 0;
	while (i < len)
	{
		res[i] = c;
		i++;
	}
	return (res);
}

void	filler_f(char *res, char *fill, struct s_tfs data, int sign)
{
	if (data.zero == -1 && fill != NULL && data.minus == -1)
		ft_putstr(fill);
	if (sign == 1)
		ft_putchar('-');
	else if (data.plus == 1)
		ft_putchar('+');
	else if (data.space == 1)
		ft_putchar(' ');
	if (data.zero == 1 && fill != NULL && data.minus == -1)
		ft_putstr(fill);
	ft_putstr(res);
	if (data.grid == 1 && ft_strchr(res, '.') == NULL)
		ft_putchar('.');
	if (fill != NULL && data.minus == 1)
		ft_putstr(fill);
	if (fill != NULL)
		free(fill);
}
