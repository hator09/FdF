/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:37:50 by martisan          #+#    #+#             */
/*   Updated: 2025/04/24 21:59:07 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		signo;
	long	num;
	int		i;

	signo = 1;
	num = 0;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return ((int)num * signo);
}
