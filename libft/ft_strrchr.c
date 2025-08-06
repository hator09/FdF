/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 20:34:44 by martisan          #+#    #+#             */
/*   Updated: 2025/04/30 20:57:33 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	if (c == 0)
		return ((char *)(&s[i]));
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i--;
	}
	return (0);
}
