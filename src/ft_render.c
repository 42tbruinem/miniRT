/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_render.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 12:57:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/02 14:53:10 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_render(t_data *data)
{
//	mlx_pixel_put(data->mlx.data, data->mlx.window, data->width / 2, data->height / 2, 0x00FFFF);
	mlx_pixel_put(data->mlx.data, data->mlx.window, data->width / 4, data->height / 4, 0x00FFFF);
//	mlx_pixel_put(data->mlx.data, data->mlx.window, data->width / 2, data->height / 4, 0x00FFFF);
//	mlx_pixel_put(data->mlx.data, data->mlx.window, data->width / 4, data->height / 4, 0x00FFFF);
}
