/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:42:39 by martisan          #+#    #+#             */
/*   Updated: 2025/05/26 21:10:00 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, size_t *printed)
{
	write(1, &c, 1);
	(*printed)++;
}

size_t	print_char(va_list arg)
{
	size_t	printed;
	char	c;

	c = (char)va_arg(arg, int);
	printed = 0;
	ft_putchar(c, &printed);
	return (printed);
}
