/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:55:22 by fprovolo          #+#    #+#             */
/*   Updated: 2019/12/24 18:52:39 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>  // for test!
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef	struct	s_flags
{
	char		alt_out;
	char		zero_padding;
	char		left;
	char		first_space;
	char		sign;
	char		thousands;
	int			min_width;
	int			precision;
	char		mod_short;
	char		mod_long;
	char		mod_long_double;
	size_t		len;
}				t_flags;

int		ft_printf(char *str, ...);
void	init_flags(t_flags *flags);
void	parse_conversion(char **ptr, t_flags *flags, va_list ap);

#endif