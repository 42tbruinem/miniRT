/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_initialization_functs.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 13:38:57 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/14 20:13:22 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_initf		ft_init_funct(int id)
{
	static const t_initf functs[9] = {
		[RES] = &ft_resolution_init,
		[AMB] = &ft_ambient_init,
		[CAM] = &ft_camera_init,
		[LIGHT] = &ft_light_init,
		[SPH] = &ft_sphere_init,
		[PLN] = &ft_plane_init,
		[SQR] = &ft_square_init,
		[CYL] = &ft_cylinder_init,
		[TRI] = &ft_triangle_init,
	};

	printf("I can enter the init funct jumptable with %d\n", id);
	if (id != -1)
		return (functs[id]);
	return (NULL);
}
