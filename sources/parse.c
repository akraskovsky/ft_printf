/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 17:10:19 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/24 19:03:07 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_flag(t_flags *flags, char f)
{
	return ;
}

void	add_width(t_flags *flags, char c)
{
	return ;
}

void	add_presize(t_flags *flags, char c)
{
	return ;
}

void	parse_conversion(char **ptr, t_flags *flags, va_list ap)
{
	int		num;
	
	*ptr += 1;
	while (ft_strchr("-+ 0#", **ptr))
	{
		add_flags(flags, **ptr);
		*ptr += 1;
	}
	while (ft_strchr("1234566789", **ptr))
	{
		add_width(flags, **ptr);
		*ptr += 1;
	}
	if (**ptr == '.')
		*ptr += 1;
	while (ft_strchr("1234566789", **ptr))
	{
		add_width(flags, **ptr);
		*ptr += 1;
	}
	while (ft_strchr("h", **ptr))
	{
		add_(flags, **ptr);
		*ptr += 1;
	}

	return ;
}