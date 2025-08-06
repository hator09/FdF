/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:41:23 by martisan          #+#    #+#             */
/*   Updated: 2025/08/04 15:15:25 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*checked_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	free_data(t_data *data)
{
	int	i;

	if (data->map->points)
	{
		i = 0;
		while (i < data->map->height)
		{
			free(data->map->points[i]);
			i++;
		}
		free(data->map->points);
	}
	free(data->map);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->guide_img)
		mlx_destroy_image(data->mlx, data->guide_img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 4)
		data->scale *= 1.1;
	if (button == 5)
		data->scale *= 0.9;
	if (button == 1)
	{
		data->is_dragging = 1;
		data->last_mouse_x = x;
		data->last_mouse_y = y;
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		data->is_dragging = 0;
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int	dx;
	int	dy;

	if (data->is_dragging)
	{
		dx = x - data->last_mouse_x;
		dy = y - data->last_mouse_y;
		data->offset_x += dx;
		data->offset_y += dy;
		data->last_mouse_x = x;
		data->last_mouse_y = y;
	}
	return (0);
}
