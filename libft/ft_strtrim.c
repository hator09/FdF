/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:44:37 by martisan          #+#    #+#             */
/*   Updated: 2025/05/02 15:56:04 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	start;
	char	*newstr;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && in_set(s1[start], set))
	{
		start++;
	}
	while (end > start && in_set(s1[end - 1], set))
	{
		end--;
	}
	newstr = malloc(end - start + 1);
	if (!newstr)
		return (0);
	while (s1[start] && start < end)
	{
		newstr[i++] = s1[start++];
	}
	newstr[i] = '\0';
	return (newstr);
}
