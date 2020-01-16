/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_input_key.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 13:36:17 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/16 16:51:46 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_mlx_cam_move(int keycode, t_data *data)
{
	t_matrix	dup;
	t_matrix	add;

	if (keycode == Z)
		data->cams->prop.pivot.z -= 0.5;
	if (keycode == X)
		data->cams->prop.pivot.z += 0.5;
	if (keycode == D)
		data->cams->prop.pivot.x += 0.5;
	if (keycode == A)
		data->cams->prop.pivot.x -= 0.5;
	if (keycode == W)
	{
		data->cams->prop.pivot.y += 0.5;
//		ft_matrix_dup(data->cams->c2w, dup);
//		ft_matrix_t(ft_vec_init(0, 0.5, 0), add);
//		ft_matrix_mult(dup, add, data->cams->c2w);
	}
	if (keycode == S)
		data->cams->prop.pivot.y -= 0.5;
	ft_c2w_update(data->cams);
	ft_mlx_render(data);
	return (0);
}

int	ft_mlx_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!param)
		return (0);
	if (keycode == SPACE)
		mlx_clear_window(data->mlx.data, data->mlx.window);
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(data->mlx.data, data->mlx.window);
		ft_data_clear(data);
		mlx_destroy_image(data->mlx.data, data->mlx.image1);
		mlx_destroy_image(data->mlx.data, data->mlx.image2);
		mlx_destroy_window(data->mlx.data, data->mlx.window);
		exit(0);
	}
	if (keycode == Z || keycode == X || keycode == W ||
		keycode == S || keycode == A || keycode == D)
		return (ft_mlx_cam_move(keycode, data));
	return (0);
}
