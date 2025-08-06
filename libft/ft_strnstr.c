/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:57:17 by martisan          #+#    #+#             */
/*   Updated: 2025/05/02 15:55:56 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if ((!big || !little) && len == 0)
		return (0);
	if (*little == '\0')
		return ((char *)big);
	while (big[j] && j < len)
	{
		if (big[j] == *little)
		{
			i = 0;
			while (little[i] && big[j + i] == little[i] && (j + i) < len)
			{
				i++;
			}
			if (little[i] == '\0')
			{
				return ((char *)&big[j]);
			}
		}
		j++;
	}
	return (0);
}
