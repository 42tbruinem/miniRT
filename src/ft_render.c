/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_render.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 12:57:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/08 09:45:13 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_mlx_render(t_data *data)
{
	int				x;
	int				y;
	unsigned int	col;
	t_ray			ray;

	y = 0;
	col = 0;
#ifdef RAW
	printf("P6\n%d %d\n255\n", data->width, data->height);
#endif
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			col = ft_col_tohex(data->amb.col) * data->amb.bright;
			ray = ft_ray_init(data, x, y);
			ray.origin = ft_vec_init(0, 0, 0);
			ft_ray_coll(data, ray, &col);
//			color = ft_col_torgb((unsigned int)col);
//			ft_mlx_pixel_to_img(data->mlx.image, x, y, col);
//			ft_mlx_pixtoimg(data, x, y, col);
#ifdef RAW
	printf("%c%c%c", (col & 0xFF000000) >> 16, (col & 0x00FF0000) >> 8, col & 0x0000FF00);
#endif
			x++;
		}
		y++;
	}
//	mlx_put_image_to_window(data->mlx.data, data->mlx.window,
//			data->mlx.image, 0, 0);
	return (0);
}
