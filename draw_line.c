/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:10:11 by martisan          #+#    #+#             */
/*   Updated: 2025/08/04 15:10:56 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static void	draw_points(t_point *p0, t_point *p1, t_data *data, t_line_data	*l)
{
	int			x0;
	int			y0;
	t_line_data	ld;
	int			e2;

	ld = *l;
	x0 = (int)p0->x_proj;
	y0 = (int)p0->y_proj;
	while (!(x0 == (int)p1->x_proj && y0 == (int)p1->y_proj))
	{
		my_mlx_pixel_put(data, x0, y0, p0->color);
		e2 = 2 * ld.err;
		if (e2 > -ld.dy)
		{
			ld.err -= ld.dy;
			x0 += ld.sx;
		}
		if (e2 < ld.dx)
		{
			ld.err += ld.dx;
			y0 += ld.sy;
		}
	}
}

void	draw_line(t_point *p0, t_point *p1, t_data *data)
{
	t_line_data	ld;
	int			x0;
	int			y0;
	int			x1;
	int			y1;

	x0 = (int)p0->x_proj;
	y0 = (int)p0->y_proj;
	x1 = (int)p1->x_proj;
	y1 = (int)p1->y_proj;
	ld.dx = ft_abs(x1 - x0);
	ld.dy = ft_abs(y1 - y0);
	if ((x0 < x1))
		ld.sx = 1;
	else
		ld.sx = -1;
	if ((y0 < y1))
		ld.sy = 1;
	else
		ld.sy = -1;
	ld.err = ld.dx - ld.dy;
	draw_points(p0, p1, data, &ld);
}
