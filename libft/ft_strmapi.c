/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:53:17 by martisan          #+#    #+#             */
/*   Updated: 2025/05/02 15:55:46 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;

	i = 0;
	new_str = malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/* 
char	mi_funcion(unsigned int i, char c)
{
	if (i % 2 == 1)
		return (toupper(c));  // Convierte solo si la posición es impar
	return (c);
}

int main(void)
{
	char *resultado = ft_strmapi("hola mundo", mi_funcion);
	printf("%s\n", resultado);  // hOlA mUnDo
	free(resultado);
	return 0;
}
 */