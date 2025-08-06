/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:02:47 by martisan          #+#    #+#             */
/*   Updated: 2025/08/04 15:13:59 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_data *vars)
{
	if (vars->win)
		free_data(vars);
	exit(0);
}

int	render_next_frame(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = NULL;
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	render_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	if (data->guide_img)
		mlx_put_image_to_window(data->mlx, data->win, data->guide_img, 0, 0);
	return (0);
}

void	set_iso_view(t_data *data)
{
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->scale = DEF_SCALE;
	data->offset_y = HEIGHT / 2;
	data->offset_x = WIDTH / 2;
	data->projection_mode = ISOMETRIC;
}

void	ft_window(t_data *data)
{
	int	img_guide_w;
	int	img_guide_h;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FdF martisan");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	set_iso_view(data);
	data->is_dragging = 0;
	data->z_scale = 1.0;
	data->guide_img = mlx_xpm_file_to_image(data->mlx, "FdF.xpm",
			&img_guide_w, &img_guide_h);
	if (!data->guide_img)
		ft_printf("Error: no se pudo cargar FdF.xpm\n");
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_hook(data->win, 17, 0L, close_window, data);
	mlx_hook(data->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_press, data);
	mlx_hook(data->win, ButtonRelease, ButtonReleaseMask, mouse_release, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, mouse_move, data);
	mlx_loop(data->mlx);
}
