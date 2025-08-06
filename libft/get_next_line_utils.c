/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:32:16 by martisan          #+#    #+#             */
/*   Updated: 2025/05/26 18:43:07 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*s;
	int		len;
	int		i;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_strdup("");
	new = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j++];
		i++;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*f_substr(char *s, size_t start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	new = (char *)malloc(len + 1);
	if (!new)
	{
		free(s);
		return (NULL);
	}
	while (s[start + i] && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
