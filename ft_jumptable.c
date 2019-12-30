/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_jumptable.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 13:38:57 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 15:33:25 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_initf		ft_jumptable(int id)
{
	const t_initf functs[9] = {
		[0] = &ft_resolution_init,
		[1] = &ft_ambient_init,
		[2] = &ft_camera_init,
		[3] = &ft_light_init,
		[4] = &ft_sphere_init,
		[5] = &ft_plane_init,
		[6] = &ft_square_init,
		[7] = &ft_cylinder_init,
		[8] = &ft_triangle_init,
	};

	return (functs[id]);
}
