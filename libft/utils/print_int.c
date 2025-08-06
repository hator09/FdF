/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:49:19 by martisan          #+#    #+#             */
/*   Updated: 2025/05/13 19:08:17 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n, size_t *printed)
{
	char	c;
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		(*printed)++;
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, printed);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
	(*printed)++;
}

size_t	print_int(va_list arg, t_flags flag)
{
	size_t	printed;
	int		n;

	n = va_arg(arg, int);
	printed = 0;
	if (n >= 0)
	{
		if (flag.plus == 1)
			printed += write(1, "+", 1);
		else if (flag.space == 1 && flag.plus == 0)
			printed += write(1, " ", 1);
	}
	ft_putnbr(n, &printed);
	return (printed);
}
