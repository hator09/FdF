/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:28:26 by martisan          #+#    #+#             */
/*   Updated: 2025/08/04 15:09:34 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(float *y, float *z, float angle)
{
	float	old_y;

	old_y = *y;
	*y = old_y * cos(angle) - *z * sin(angle);
	*z = old_y * sin(angle) + *z * cos(angle);
}

void	rotate_y(float *x, float *z, float angle)
{
	float	old_x;

	old_x = *x;
	*x = old_x * cos(angle) + *z * sin(angle);
	*z = -old_x * sin(angle) + *z * cos(angle);
}

void	rotate_z(float *x, float *y, float angle)
{
	float	old_x;

	old_x = *x;
	*x = old_x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
}

static void	key_aux(int keycode, t_data *data)
{
	if (keycode == 113)
		data->angle_z -= 0.1;
	if (keycode == 101)
		data->angle_z += 0.1;
	if (keycode == 119)
		data->angle_y -= 0.1;
	if (keycode == 115)
		data->angle_y += 0.1;
	if (keycode == 97)
		data->angle_x -= 0.1;
	if (keycode == 100)
		data->angle_x += 0.1;
}

int	key_hook(int keycode, t_data *data)
{
	key_aux(keycode, data);
	if (keycode == 65307)
	{
		free_data(data);
		exit(0);
	}
	if (keycode == 65451 || keycode == 61)
		data->z_scale += 0.1;
	if (keycode == 65453 || keycode == 45)
		data->z_scale -= 0.1;
	if (keycode == 112)
	{
		if (data->projection_mode == ISOMETRIC)
			data->projection_mode = PARALLEL;
	}
	if (keycode == 105)
		set_iso_view(data);
	return (0);
}
