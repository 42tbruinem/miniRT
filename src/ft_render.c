/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_render.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 12:57:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/16 00:15:23 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_bmp_header(t_data *data)
{
	int	zero[24];

	write(data->fd, "BM\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	write(data->fd, "\x36\x00\x00\x00\x28\x00\x00\x00", 8);
	write(data->fd, &data->width, 4);
	write(data->fd, &data->width, 4);
	write(data->fd, "\x01\x00\x18\x00", 4);
	write(data->fd, zero, 24);
}

int		ft_bmp_render(t_data *data)
{
	int				x;
	int				y;
	t_col			col;
	int				zero[4];

	y = data->height;
	ft_bmp_header(data);
//	dprintf(data->fd, "P6\n%d %d\n255\n", data->width, data->height);
	while (y >= 0)
	{
		x = data->width;
		while (x >= 0)
		{
			col = ft_col_mult(ft_col_init(1, 1, 1), data->amb.col, data->amb.bright);
			ft_ray_coll(data, ft_ray_init(data, x, y), &col);
//			write(data->fd, &col.r, 1);
//			write(data->fd, &col.g, 1);
//			write(data->fd, &col.b, 1);
			write(data->fd, &col.b, 1);
			write(data->fd, &col.g, 1);
			write(data->fd, &col.r, 1);
			x--;
		}
		y--;
	}
	return (0);
}

int		ft_mlx_render(t_data *data)
{
	int				x;
	int				y;
	t_col			col;
	t_raydata		rdata;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			rdata.col = ft_col_mult(ft_col_init(1, 1, 1), data->amb.col, data->amb.bright);
			rdata.ray = ft_ray_init(data, x, y);
			ft_cameraray(data, &rdata);
			ft_mlx_pixel_to_img(data, x, y, col);
			x++;
		}
		y++;
	}
	ft_mlx_img_to_win(data);
	return (0);
}
