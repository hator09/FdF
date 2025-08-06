/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:05:02 by martisan          #+#    #+#             */
/*   Updated: 2025/05/02 16:29:19 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

void	ft_strfree(char **arr, int j)
{
	while (--j >= 0)
		free(arr[j]);
	free(arr);
}

static void	ft_auxsplit(char const *s, char c, char **arr, int start)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && start == -1)
			start = i;
		if ((s[i] == c || s[i + 1] == '\0') && start != -1)
		{
			end = i + 1;
			if (s[i] == c)
				end = i;
			arr[j] = ft_substr(s, start, end - start);
			if (!arr[j])
				return (ft_strfree(arr, j));
			j++;
			start = -1;
		}
		i++;
	}
	arr[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		start;

	start = -1;
	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	ft_auxsplit(s, c, arr, start);
	return (arr);
}

/* void	print_split(char **split)
{
	int	i = 0;
	while (split[i])
	{
		printf("Parte %d: %s\n", i, split[i]);
		i++;
	}
}

// Función auxiliar para liberar la memoria del resultado
void	free_split(char **split)
{
	int	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(void)
{
	char const *str = "hola,esto,es,una,prueba";
	char sep = ',';

	char **resultado = ft_split(str, sep);

	if (!resultado)
	{
		printf("Error: ft_split devolvió NULL\n");
		return (1);
	}

	print_split(resultado);
	free_split(resultado);
	return (0);
} */
