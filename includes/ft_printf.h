/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:55:22 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/21 18:01:59 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# define BUFF_SIZE	60

# include <stdio.h>  // for test!
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef	struct	s_flags
{
	char		alt_out;//#
	char		zero_padding;//00000
	char		left;// -
	char		first_space;// ' ' 
	char		sign;// +
	char		thousands;//'
	char		grid;//'.'
	size_t		min_width;//
	size_t		precision;//...
	int			precision_set;
	char		mod_char;//char
	char		mod_short;//short 
	char		mod_long;//l
	char		mod_long_long;//ll
	char		mod_long_double;//L
	char		conversion;
	size_t		field_len;
	int			fd;
}				t_flags;

union			u_d_double
{
	long double		d;
	unsigned char	c[16];
};

int		ft_printf(char *str, ...);
int		ft_printf_fd(int fd, char *str, ...);
void	init_flags(t_flags *flags);
int		parse_format(char **ptr, t_flags *flags, va_list ap);
int		get_argument(t_flags *flags, va_list ap);
char	*get_int(t_flags *flags, va_list ap);
char	*get_unsigned(t_flags *flags, va_list ap);
char	*get_string(t_flags *flags, va_list ap);
char	*get_character(t_flags *flags, va_list ap);
char	*ft_strnewfill(size_t len, char c);

void	print_flags(t_flags *flags);  //*** test function !!! ***//

#endif