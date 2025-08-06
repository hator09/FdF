/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:49:49 by martisan          #+#    #+#             */
/*   Updated: 2025/05/13 18:59:00 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putx(unsigned int nb, char *base, size_t *printed)
{
	char	c;

	if (nb > 15)
	{
		ft_putx(nb / 16, base, printed);
	}
	c = base[nb % 16];
	write(1, &c, 1);
	(*printed)++;
}

size_t	print_x(va_list arg, int up, t_flags flag)
{
	size_t			printed;
	unsigned int	n;
	char			*base;

	n = va_arg(arg, unsigned int);
	printed = 0;
	if (up)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (flag.hash == 1)
	{
		if (up)
			printed += write(1, "0X", 2);
		else
			printed += write(1, "0x", 2);
	}
	ft_putx(n, base, &printed);
	return (printed);
}
