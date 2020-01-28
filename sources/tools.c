/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:22:16 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/28 11:58:31 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->alt_out = 0;
	flags->zero_padding = 0;
	flags->left = 0;
	flags->first_space = 0;
	flags->sign = 0;
	flags->thousands = 0;
	flags->min_width = 0;
	flags->precision = 0;
	flags->precision_set = 0;
	flags->mod_char = 0;
	flags->mod_short = 0;
	flags->mod_long = 0;
	flags->mod_long_long = 0;
	flags->mod_long_double = 0;
	flags->conversion = 0;
	flags->field_len = 0;
	return ;
}

char	*ft_strnewfill(size_t len, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(len + 1);
	if (str != NULL)
		while (i < len)
			str[i++] = c;
	str[len] = '\0';
	return (str);
}
