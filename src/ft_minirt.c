/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_minirt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 12:47:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/08 09:48:49 by tbruinem      ########   odam.nl         */
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
	//ft_data_print(&data);
	if (ft_mlx_init(&data) == 0)
		return (ft_error(error));
	error = ft_mlx_render(&data);
	if (error)
		return (ft_error(error));
	mlx_hook(data.mlx.window, KEY_PRESS_CODE, 1L << 0, ft_mlx_keypress, &data);
	mlx_loop(data.mlx.data);
	return (0);
}
