/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:11:26 by martisan          #+#    #+#             */
/*   Updated: 2025/05/02 15:53:41 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(int nb, char *s, int *i)
{
	char	c;
	long	n;

	n = nb;
	if (n < 0)
	{
		s[*i] = '-';
		(*i)++;
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, s, i);
	}
	c = (n % 10) + '0';
	s[*i] = c;
	(*i)++;
}

static int	ft_lennum(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb <= 0)
	{
		len++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = ft_lennum(n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_putnbr(n, s, &i);
	s[i] = '\0';
	return (s);
}
