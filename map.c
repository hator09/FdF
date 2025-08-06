/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martisan <martisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:45:24 by martisan          #+#    #+#             */
/*   Updated: 2025/08/04 15:17:33 by martisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	check_width(char **line_split, int *width)
{
	int	x;

	x = 0;
	while (line_split[x])
		x++;
	if (*width == 0)
		*width = x;
	else if (*width != x)
	{
		ft_printf("Error: file contains rows with different number of columns");
		exit(1);
	}
}

void	check_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	**line_split;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	map->width = 0;
	map->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_split = ft_split(line, ' ');
		check_width(line_split, &map->width);
		(map->height)++;
		free(line);
		free_split(line_split);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

static void	fill_points(char **line_split, t_point **points, int y)
{
	char	**z_color;
	int		x;

	x = 0;
	while (line_split[x])
	{
		z_color = ft_split(line_split[x], ',');
		points[y][x].z = atoi(z_color[0]);
		if (points[y][x].z >= 1 && points[y][x].z <= 11)
			points[y][x].color = SECOLOR;
		else if (points[y][x].z > 11)
			points[y][x].color = THICOLOR;
		else
			points[y][x].color = WHITE;
		if (z_color[1])
			points[y][x].color = ft_strtol(z_color[1]);
		points[y][x].y = y;
		points[y][x].x = x;
		free_split(z_color);
		x++;
	}
}

void	fill_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	**line_split;
	t_point	**points;
	int		y;

	fd = open(file, O_RDONLY);
	points = (t_point **)checked_malloc(sizeof(t_point *) * map->height);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_split = ft_split(line, ' ');
		points[y] = (t_point *)checked_malloc(sizeof(t_point) * map->width);
		fill_points(line_split, points, y);
		free(line);
		free_split(line_split);
		line = get_next_line(fd);
		y++;
	}
	map->points = points;
	close(fd);
}
