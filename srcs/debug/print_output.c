/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmuramat <tmuramat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:24:30 by tmuramat          #+#    #+#             */
/*   Updated: 2023/02/11 22:24:36 by tmuramat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "constant.h"
#include "ft_printf.h"

void	print_input(char *line)
{
	ft_printf("\n%s<<<< INPUT %s\n", RED, DEFAULT);
	ft_printf("%s\n", line);
}

void	print_output(void)
{
	ft_printf("%sOUTPUT >>>>%s\n", RED, DEFAULT);
}
