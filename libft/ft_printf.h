/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:49:39 by martisan          #+#    #+#             */
/*   Updated: 2025/05/26 21:30:02 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

typedef struct s_flags
{
	int	plus;
	int	space;
	int	hash;
}	t_flags;

int		ft_printf(char const *format, ...);
size_t	print_int(va_list arg, t_flags flag);
size_t	print_char(va_list arg);
size_t	print_p(va_list arg);
size_t	print_str(va_list arg);
size_t	print_u(va_list arg);
size_t	print_x(va_list arg, int up, t_flags flag);