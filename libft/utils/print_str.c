/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:32:22 by martisan          #+#    #+#             */
/*   Updated: 2025/05/13 18:59:09 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstr(char *str, size_t *printed)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
		(*printed)++;
	}
}

size_t	print_str(va_list arg)
{
	size_t	printed;
	char	*str;

	str = va_arg(arg, char *);
	printed = 0;
	if (!str)
		str = "(null)";
	ft_putstr(str, &printed);
	return (printed);
}
