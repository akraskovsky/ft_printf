/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:10:19 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/21 18:37:11 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flags(t_flags *flags, char **ptr)
{
	while (ft_strchr("-+' 0#", **ptr))
	{
		if (**ptr == '-')
			flags->left = 1;
		else if (**ptr == '+')
			flags->sign = 1;
		else if (**ptr == '\'')
			flags->thousands = 1;
		else if (**ptr == ' ')
			flags->first_space = 1;
		else if (**ptr == '0')
			flags->zero_padding = 1;
		else if (**ptr == '#')
			flags->alt_out = 1;
		(*ptr)++;
	}
	return ;
}

void	check_width(t_flags *flags, char **ptr)
{
	if (ft_strchr("123456789", **ptr))
		while (ft_strchr("0123456789", **ptr))
		{
			flags->min_width = flags->min_width * 10 + (**ptr - '0');
			(*ptr)++;
		}
	return ;
}

void	check_precision(t_flags *flags, char **ptr)
{
	if (**ptr == '.')
	{
		flags->precision_set = 1;
		(*ptr)++;
		while (ft_strchr("0123456789", **ptr))
		{
			flags->precision = flags->precision * 10 + (**ptr - '0');
			(*ptr)++;
		}
	}
	return ;
}

void	check_modifier(t_flags *flags, char **ptr)
{
	if (**ptr == 'h' && (*ptr)[1] == 'h')
		flags->mod_char = 1;
	else if (**ptr == 'h' && (*ptr)[1] != 'h')
		flags->mod_short = 1;
	else if (**ptr == 'l' && (*ptr)[1] != 'l')
		flags->mod_long = 1;
	else if (**ptr == 'l' && (*ptr)[1] == 'l')
		flags->mod_long_long = 1;
	else if (**ptr == 'L')
		flags->mod_long_double = 1;
	if (flags->mod_short || flags->mod_long || flags->mod_long_double)
		(*ptr)++;
	if (flags->mod_char || flags->mod_long_long)
		(*ptr) += 2;
	return ;
}

int		parse_format(char **ptr, t_flags *flags, va_list ap)
{
	int	ret;

	ret = 1;
	*ptr += 1;
	init_flags(flags);
	check_flags(flags, ptr);
	check_width(flags, ptr);
	check_precision(flags, ptr);
	check_modifier(flags, ptr);
	flags->conversion = **ptr;
	(*ptr)++;
	ret = get_argument(flags, ap);
	return (ret);
}
