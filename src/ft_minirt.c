/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_minirt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 12:47:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/01 21:27:09 by tbruinem      ########   odam.nl         */
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
	ft_data_print(&data);
	return (0);
}
