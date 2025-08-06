/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:27:24 by martisan          #+#    #+#             */
/*   Updated: 2025/05/13 18:59:05 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putuns(unsigned int nb, size_t *printed)
{
	char	c;

	if (nb > 9)
	{
		ft_putuns(nb / 10, printed);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
	(*printed)++;
}

size_t	print_u(va_list arg)
{
	size_t			printed;
	unsigned int	n;

	n = va_arg(arg, unsigned int);
	printed = 0;
	ft_putuns(n, &printed);
	return (printed);
}
