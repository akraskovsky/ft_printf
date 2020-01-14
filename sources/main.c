/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:58:19 by fprovolo          #+#    #+#             */
/*   Updated: 2020/01/14 18:11:58 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     main(void)
{
    char	*str = "Mystring";
    long	num;
    int     value;
    int     check;
    
	check = ft_printf("Percent sign%%is printed%%%%twice\n");
    printf ("check=%d\n", check);
	   check = printf("Percent sign%%is printed%%%%twice\n");
    printf ("check=%d\n\n", check);

    value = 0;
    check = ft_printf("Integer \'%d\' second \'%+10d\' third \'%-+10d\' fourth \'%015.10d\'.\n", value, value, value, value);
    printf ("check=%d\n", check);
       check = printf("Integer \'%d\' second \'%+10d\' third \'%-+10d\' fourth \'%015.10d\'.\n", value, value, value, value);
    printf ("check=%d\n\n", check);

    num = 1;
    check = ft_printf("long num=\'%#lx\' \'%lX\' \'%#020lx\'\n", num, num, num);
    printf ("check=%d\n", check);
       check = printf("long num=\'%#lx\' \'%lX\' \'%#020lx\'\n", num, num, num);
    printf ("check=%d\n\n", check);

    check = ft_printf("string=\'%s\' \'%15s\' \'%5s\' \'%-10.5s\'\n", str, str, str, str);
    printf ("check=%d\n", check);
    check = ft_printf("string=\'%s\' \'%15s\' \'%5s\' \'%-10.5s\'\n", str, str, str, str);
    printf ("check=%d\n\n", check);
}
