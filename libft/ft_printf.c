/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:49:34 by martisan          #+#    #+#             */
/*   Updated: 2025/05/13 19:02:18 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*check_flags(const char *fmt, t_flags *flag)
{
	while (*fmt == ' ' || *fmt == '+' || *fmt == '#')
	{
		if (*fmt == '+')
			flag->plus = 1;
		else if (*fmt == ' ')
			flag->space = 1;
		else if (*fmt == '#')
			flag->hash = 1;
		fmt++;
	}
	return (fmt);
}

static const char	*print_f(const char *fmt, va_list *args, size_t *printed)
{
	t_flags	flags;

	flags.plus = 0;
	flags.space = 0;
	flags.hash = 0;
	fmt = check_flags(fmt, &flags);
	if (*fmt == 'd' || *fmt == 'i')
		*printed += print_int(*args, flags);
	else if (*fmt == 'u')
		*printed += print_u(*args);
	else if (*fmt == 's')
		*printed += print_str(*args);
	else if (*fmt == 'c')
		*printed += print_char(*args);
	else if (*fmt == 'x' || *fmt == 'X')
		*printed += print_x(*args, *fmt == 'X', flags);
	else if (*fmt == 'p')
		*printed += print_p(*args);
	else if (*fmt == '%')
		*printed += write(1, "%", 1);
	return (fmt);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	printed;

	va_start(args, format);
	printed = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			format = print_f(format, &args, &printed);
		}
		else
		{
			write(1, format, 1);
			printed++;
		}
		format++;
	}
	va_end(args);
	return (printed);
}
