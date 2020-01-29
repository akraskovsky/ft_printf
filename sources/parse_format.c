/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:10:19 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/29 15:29:32 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(t_flags *flags, char **ptr)
{
	while (ft_strchr("-+ 0#", **ptr) && **ptr != '\0')
	{
		if (**ptr == '-')
			flags->left = 1;
		else if (**ptr == '+')
			flags->sign = 1;
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

static void	check_precision(t_flags *flags, char **ptr, va_list ap)
{
	int		prec;

	flags->precision_set = 1;
	(*ptr)++;
	while (ft_isdigit(**ptr) || **ptr == '*')
	{
		if (**ptr == '*')
		{
			prec = va_arg(ap, int);
			flags->precision = (prec >= 0) ? prec : flags->precision;
			(*ptr)++;
		}
		if (ft_isdigit(**ptr))
		{
			flags->precision = 0;
			while (ft_isdigit(**ptr))
			{
				flags->precision = flags->precision * 10 + (**ptr - '0');
				(*ptr)++;
			}
		}
	}
	return ;
}

static void	check_width(t_flags *flags, char **ptr, va_list ap)
{
	int		width;
	
	while (ft_isdigit(**ptr) || **ptr == '*')
	{
		if (**ptr == '*')
		{
			width = va_arg(ap, int);
			flags->min_width = (width >= 0) ? width : width * -1;
			flags->left = (width >= 0) ? flags->left : 1;
			(*ptr)++;
		}
		if (ft_isdigit(**ptr))
		{
			flags->min_width = 0;
			while (ft_isdigit(**ptr))
			{
				flags->min_width = flags->min_width * 10 + (**ptr - '0');
				(*ptr)++;
			}
		}
	}
	if (**ptr == '.')
		check_precision(flags, ptr, ap);
	return ;
}

static void	check_modifier(t_flags *flags, char **ptr)
{
	if (**ptr == 'h' && (*ptr)[1] == 'h')
		flags->mod_char = 1;
	else if (**ptr == 'h')
		flags->mod_short = 1;
	else if (**ptr == 'l' && (*ptr)[1] == 'l')
		flags->mod_long_long = 1;
	else if (**ptr == 'l')
		flags->mod_long = 1;
	else if (**ptr == 'L')
		flags->mod_long_double = 1;
	if (flags->mod_short || flags->mod_long || flags->mod_long_double)
		(*ptr)++;
	if (flags->mod_char || flags->mod_long_long)
		(*ptr) += 2;
	return ;
}

int			parse_format(char **ptr, t_flags *flags, va_list ap)
{
	if (**ptr == '{')
		return (ft_set_colors(ptr, flags));
	*ptr += 1;
	init_flags(flags);
	check_flags(flags, ptr);
	check_width(flags, ptr, ap);
	check_modifier(flags, ptr);
	if (ft_strchr("diouxXpsc%fFgGeE", **ptr) && **ptr != '\0')
	{
		flags->conversion = **ptr;
		(*ptr)++;
		return (get_argument(flags, ap));
	}
	return (1);
}
