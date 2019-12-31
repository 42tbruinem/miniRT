/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_minirt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 12:47:02 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/31 16:58:30 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char **input)
{
	t_data	data;
	int		fd;

	if (argc < 2 || argc > 2)
		return (ft_error(1));
	fd = open(input[1], O_RDONLY);
	if (ft_is_valid(input[1]) == 0)
		return (ft_error(1));
	if (read(fd, (void *)0, 0) == -1)
		return (ft_error(1));
	data = ft_data_get(fd);
	ft_data_print(&data);
	return (0);
}
