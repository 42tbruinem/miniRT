/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_minirt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 12:47:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/04 16:24:12 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char **input)
{
	t_data	data;
	int		fd;
	int		error;

	error = ft_filter_input(argc, input);
	if (error)
		return (ft_error(error));
	fd = open(input[1], O_RDONLY);
	error = ft_data_get(&data, fd);
	if (error)
		return (ft_error(error));
//	data.mlx.data = mlx_init();
//	data.mlx.window =	mlx_new_window(data.mlx.data,
//						data.width, data.height, "Mini RayTracer");
	ft_data_print(&data);
	error = ft_render(&data);
	if (error)
		return (ft_error(error));
//	mlx_loop(data.mlx.data);
	return (0);
}
