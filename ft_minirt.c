/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_minirt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 12:47:02 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 17:44:33 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char **input)
{
	t_data	data;
	int		fd;

	if (argc < 2 || argc > 2)
		return (ft_error());
	fd = open(input[1], O_RDONLY);
	if (read(fd, (void *)0, 0) == -1)
		return (ft_error());
	data = ft_scene_read(fd);
	return (0);
}
