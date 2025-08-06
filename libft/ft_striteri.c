/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:15:56 by martisan          #+#    #+#             */
/*   Updated: 2025/04/24 19:22:20 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* #include <ctype.h>
#include <stdio.h>

void	to_upper(unsigned int i, char *c)
{
	(void)i;
	*c = toupper(*c);
}

int	main(void)
{
	char str[] = "hola mundo";
	ft_striteri(str, to_upper);
	printf("%s\n", str);  // Imprime: HOLA MUNDO
	return 0;
} */
