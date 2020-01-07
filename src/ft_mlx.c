/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mlx.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:20:13 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/07 12:06:07 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_mlx_pixel_to_img(void *img, int x, int y, unsigned int color)
{
	int				ll;
	int				bpp;
	int				endian;
	char			*image;

	image = mlx_get_data_addr(img, &bpp, &ll, &endian);
//	printf("bie ba\n");
//	printf("boe ba\n");
	image += (y * ll + (x * (bpp / 8)));
	*(unsigned int *)image = color;
//	printf("banaantjes\n");
}

void	ft_mlx_pixtoimg(t_data *data, int x, int y, unsigned int col)
{
	char	*image;

	int		offset;


	offset = (y * data->mlx.ll + x * (data->mlx.bpp / 8));
	image = data->mlx.addr + offset;
//	if (x >= 0 && x < data->width && y >= 0 && y < data->height)
		*(unsigned int *)image = col;
	mlx_pixel_put(data->mlx.data, data->mlx.window, x, y, col);
}

int		ft_mlx_init(t_data *data)
{
	data->mlx.data = mlx_init();
	if (!data->mlx.data)
		return (0);
	data->mlx.window = mlx_new_window(data->mlx.data,
						data->width, data->height, "Mini RayTracer");
	if (!data->mlx.window)
		return (0);
	data->mlx.image = mlx_new_image(data->mlx.data, data->width, data->height);
	if (!data->mlx.image)
		return (0);
//	data->mlx.addr = mlx_get_data_addr(data->mlx.image, &data->mlx.bpp,
//						&data->mlx.ll, &data->mlx.endian);
//	if (!data->mlx.addr)
//		return (0);
	return (1);
}
