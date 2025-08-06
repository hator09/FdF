/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:55:36 by martisan          #+#    #+#             */
/*   Updated: 2025/05/02 15:53:13 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (0);
	arr = malloc(nmemb * size);
	if (!arr)
		return (0);
	ft_memset(arr, 0, nmemb * size);
	return (arr);
}
