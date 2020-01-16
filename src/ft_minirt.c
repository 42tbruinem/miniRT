/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_minirt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 12:47:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 22:48:22 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char **input)
{
	t_data	data;
	int		fd;
	int		error;

	ft_data_init(&data);
	error = ft_validate_input(&data, argc, input);
	if (error)
		return (ft_error(NULL, error));
	fd = open(input[1], O_RDONLY);
	error = ft_data_get(&data, fd);
	if (error)
		return (ft_error(&data, error));
	ft_data_print(&data);
	if (ft_mlx_init(&data) == ERR_MEM)
		return (ft_error(&data, ERR_MEM));
	error = (data.save == 1) ? ft_bmp_render(&data) : ft_mlx_render(&data);
	if (error)
		return (ft_error(&data, error));
	mlx_hook(data.mlx.window, KEY_PRESS_CODE, 1L << 0, ft_mlx_keypress, &data);
	mlx_loop(data.mlx.data);
	return (0);
}
