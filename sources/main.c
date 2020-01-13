/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:58:19 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/13 20:10:48 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main(void)
{
//    char	*str = "My string";
    long	num;
    int     value;
    
    value = 545678;
    ft_printf("Integer \'%d\' \'%10d\' \'%-+10d\' \'% 010d\'.\n", value, value, value, value);
    printf("Integer \'%d\' \'%10d\' \'%-+10d\' \'% 010d\'.\n", value, value, value, value);


    num = 87687687685;
    ft_printf("long num=\'%#lx\' \'%lX\' \'%020lx\'\n", num, num, num);
    printf("long num=\'%#lx\' \'%lX\' \'%020lx\'\n", num, num, num);
}
