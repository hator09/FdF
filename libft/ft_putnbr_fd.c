/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:38:00 by martisan          #+#    #+#             */
/*   Updated: 2025/04/29 19:03:04 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_auxnbr(long n, char *snum, int *i)
{
	if (n > 9)
	{
		ft_auxnbr(n / 10, snum, i);
	}
	snum[*i] = (n % 10) + '0';
	(*i)++;
}

static char	*ft_putnbr(int nb)
{
	static char	snum[12];
	long		n;
	int			i;

	n = nb;
	i = 0;
	if (n < 0)
	{
		snum[i++] = '-';
		n = -n;
	}
	if (n == 0)
	{
		snum[i++] = '0';
	}
	else
	{
		ft_auxnbr(n, snum, &i);
	}
	snum[i] = '\0';
	return (snum);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*snum;

	snum = ft_putnbr(n);
	ft_putstr_fd(snum, fd);
}
