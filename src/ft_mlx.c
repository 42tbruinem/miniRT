/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mlx.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:20:13 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/09 10:37:46 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_mlx_img_to_win(t_data *data)
{
	if (data->mlx.frame % 2 == 0)
		mlx_put_image_to_window(data->mlx.data, data->mlx.window,
			data->mlx.image2, 0, 0);
	else
		mlx_put_image_to_window(data->mlx.data, data->mlx.window,
			data->mlx.image1, 0, 0);
}

void	ft_mlx_pixel_to_img(t_data *data, int x, int y, unsigned int color)
{
	char	*image;

	if (data->mlx.frame % 2 == 0)
		image = data->mlx.addr2;
	else
		image = data->mlx.addr1;
	image += (y * data->mlx.ll + (x * (data->mlx.bpp / 8)));
	*(unsigned int *)image = color;
}

int		ft_mlx_init(t_data *data)
{
	data->mlx.frame = 1;
	data->mlx.data = mlx_init();
	if (!data->mlx.data)
		return (ERR_MEM);
	data->mlx.window = mlx_new_window(data->mlx.data,
						data->width, data->height, "Mini RayTracer");
	if (!data->mlx.window)
		return (ERR_MEM);
	data->mlx.image1 = mlx_new_image(data->mlx.data, data->width, data->height);
	data->mlx.image2 = mlx_new_image(data->mlx.data, data->width, data->height);
	if (!data->mlx.image1 || !data->mlx.image2)
		return (ERR_MEM);
	data->mlx.addr1 = mlx_get_data_addr(data->mlx.image1, &data->mlx.bpp,
						&data->mlx.ll, &data->mlx.endian);
	data->mlx.addr2 = mlx_get_data_addr(data->mlx.image2, &data->mlx.bpp,
						&data->mlx.ll, &data->mlx.endian);
	if (!data->mlx.addr1 || !data->mlx.addr2)
		return (ERR_MEM);
	return (1);
}
