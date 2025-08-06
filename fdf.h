/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:39:34 by martisan          #+#    #+#             */
/*   Updated: 2025/08/04 15:21:36 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <X11/X.h>
#include "libft/libft.h"

#define WHITE 0xFFFFFF
#define SECOLOR 0xE9ED5C
#define THICOLOR 0x9DDE5D
#define DEF_SCALE 40
#define HEIGHT 1080
#define WIDTH 1920
#define PI 3.141592653589793
#define ISOMETRIC 0
#define PARALLEL 1

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	float	x_proj;
	float	y_proj;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
}	t_map;

typedef struct s_line_data
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_line_data;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	t_map	*map;

	int		offset_x;
	int		offset_y;

	float	angle_x;
	float	angle_y;
	float	angle_z;

	float	scale;

	int		is_dragging;
	int		last_mouse_x;
	int		last_mouse_y;

	float	z_scale;

	int		projection_mode;
	void	*guide_img;

}	t_data;

void	*checked_malloc(size_t size);
void	check_map(char *file, t_map *map);
void	fill_map(char *file, t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_point *p0, t_point *p1, t_data *img);
void	ft_window(t_data *data);
void	render_map(t_data *data);
void	rotate_x(float *y, float *z, float angle);
void	rotate_y(float *x, float *z, float angle);
void	rotate_z(float *x, float *y, float angle);
int		key_hook(int keycode, t_data *data);
void	set_iso_view(t_data *data);
void	free_data(t_data *data);
int		mouse_press(int button, int x, int y, t_data *data);
int		mouse_release(int button, int x, int y, t_data *data);
int		mouse_move(int x, int y, t_data *data);
