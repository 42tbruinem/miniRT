/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_render.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 12:57:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/09 10:52:41 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_mlx_render(t_data *data)
{
	int				x;
	int				y;
	unsigned int	col;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			col = ft_col_tohex(data->amb.col) * data->amb.bright;
			ft_ray_coll(data, ft_ray_init(data, x, y), &col);
//			color = ft_col_torgb((unsigned int)col);
			ft_mlx_pixel_to_img(data, x, y, col);
			x++;
		}
		y++;
	}
	ft_mlx_img_to_win(data);
	return (0);
}
