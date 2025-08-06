/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:44:53 by martisan          #+#    #+#             */
/*   Updated: 2025/08/01 21:29:12 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_projection(t_point *p, t_data *data)
{
	float	x;
	float	y;
	float	z;

	x = p->x;
	y = p->y;
	z = p->z * data->z_scale;
	if (data->projection_mode == ISOMETRIC)
	{
		rotate_x(&y, &z, data->angle_x);
		rotate_y(&x, &z, data->angle_y);
		rotate_z(&x, &y, data->angle_z);
		p->x_proj = (x - y) * cos(PI / 6) * data->scale + data->offset_x;
		p->y_proj = (x + y) * sin(PI / 6) * data->scale
			- z * data->scale + data->offset_y;
	}
	else if (data->projection_mode == PARALLEL)
	{
		p->x_proj = x * data->scale + data->offset_x;
		p->y_proj = y * data->scale - z * data->scale + data->offset_y;
	}
}

static void	render_proj(t_data *data)
{
	int		x;
	int		y;
	t_map	*map;

	map = data->map;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			apply_projection(&map->points[y][x], data);
			x++;
		}
		y++;
	}
}

void	render_map(t_data *data)
{
	int		x;
	int		y;
	t_map	*map;

	map = data->map;
	render_proj(data);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(&map->points[y][x], &map->points[y][x + 1], data);
			if (y < map->height - 1)
				draw_line(&map->points[y][x], &map->points[y + 1][x], data);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (1);
	data = checked_malloc(sizeof(t_data));
	ft_memset(data, 0, sizeof(t_data));
	data->map = checked_malloc(sizeof(t_map));
	check_map(argv[1], data->map);
	fill_map(argv[1], data->map);
	ft_window(data);
}
