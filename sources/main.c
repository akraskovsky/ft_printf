/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:58:19 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/09 19:38:13 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main(void)
{
    char	*str = "My string";
    long	num;
    
    num = 587687687685;
    ft_printf("String address %p num=%#lx address %p - will work!\n", str, num, &num);
    printf("String address %p num=%#lx address %p - will work!\n", str, num, &num);
}
