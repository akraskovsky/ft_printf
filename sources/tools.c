/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 11:22:16 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/18 15:02:20 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flags(t_flags *flags)
{
	printf("\nalt_out =         %hhd\n", flags->alt_out);
	printf("zero_padding =    %hhd\n", flags->zero_padding);
	printf("left =            %hhd\n", flags->left);
	printf("first space =     %hhd\n", flags->first_space);
	printf("sign =            %hhd\n", flags->sign);
	printf("min_width =       %zu\n", flags->min_width);
	printf("precision =       %zu\n", flags->precision);
	printf("precision_set =   %d\n", flags->precision_set);
	printf("mod_char =        %hhd\n", flags->mod_char);
	printf("mod short =       %hhd\n", flags->mod_short);
	printf("mod_long =        %hhd\n", flags->mod_long);
	printf("mod_long_long =   %hhd\n", flags->mod_long_long);
	printf("mod_long_double = %hhd\n", flags->mod_long_double);
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
