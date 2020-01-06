/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_render.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 12:57:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/06 14:27:29 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_mlx_render(t_data *data)
{
	int				x;
	int				y;
	unsigned int	col;
	t_col			color;
	t_ray			ray;

	y = 0;
	col = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			col = ft_col_tohex(data->amb.col) * data->amb.bright;
			ray = ft_ray_init(data, x, y);
			ray.origin = ft_vec_init(0, 0, 0);
			ft_ray_coll(data, ray, &col);
			color = ft_col_torgb((unsigned long)col);
			ft_mlx_pixtoimg(data, x, y, col);
			x++;
		}
		y++;
	}
//	mlx_put_image_to_window(data->mlx.data, data->mlx.window,
//		data->mlx.image, data->width, data->height);
	return (0);
}
