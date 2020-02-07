/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 12:58:19 by fprovolo          #+#    #+#             */
/*   Updated: 2020/02/07 14:56:54 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "ft_printf.h"

int	main(void)
{

	ft_printf("print test of int +20.5d : %+20.5d, and hex #x : %#x \n", 45, 124);
	ft_printf("print test of float .8f : %.8f, and exp : %e \n", 123.456, 123.456);

	ft_printf_fd(1, "\nColor test: write {BLU}in Blue {RED} and in Red {OFF} and {BLK}{BGC:YEL}with Yellow background.{OFF} Back to default.\n");

/*	ft_printf("conversion g: |%g|\n", 76547654764.98798798798798798987);
	ft_printf("conversion g: |%.2g|\n", 76547654764.98798798798798798987);
	ft_printf("conversion g: |%.g|\n\n", 76547654764.98798798798798798987);
	
	ft_printf("conversion e: |%e|\n", 76547654764.98798798798798798987);
	ft_printf("conversion e: |%.2e|\n", 76547654764.98798798798798798987);
	ft_printf("conversion e: |%.e|\n\n", 76547654764.98798798798798798987);
	
	ft_printf("conversion g: |%.8g|\n", 0.07654765476498798798798798798987);
	ft_printf("conversion e: |%.8e|\n\n", 0.07654765476498798798798798798987);
	
	ft_printf("conversion g: |%#.8g|\n", 76.0);
	ft_printf("conversion e: |%#.8e|\n", 76.0);
*/
	return (0);
}
