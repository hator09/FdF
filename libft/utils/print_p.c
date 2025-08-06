/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:10:33 by martisan          #+#    #+#             */
/*   Updated: 2025/05/26 21:19:52 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putp(unsigned long p, char *base, size_t *printed)
{
	char	c;

	if (p > 15)
	{
		ft_putp(p / 16, base, printed);
	}
	c = base[p % 16];
	write(1, &c, 1);
	(*printed)++;
}

size_t	print_p(va_list arg)
{
	size_t			printed;
	unsigned long	p;
	char			*base;

	p = va_arg(arg, unsigned long);
	printed = 0;
	base = "0123456789abcdef";
	if (p == 0)
		return (write(1, "(nil)", 5));
	printed += write(1, "0x", 2);
	ft_putp(p, base, &printed);
	return (printed);
}
