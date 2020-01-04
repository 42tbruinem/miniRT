/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_initialization_functs.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 13:38:57 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/04 16:33:06 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_initf		ft_init_funct(int id)
{
	static const t_initf functs[9] = {
		[I_RES] = &ft_resolution_init,
		[I_AMB] = &ft_ambient_init,
		[I_CAM] = &ft_camera_init,
		[I_LIGHT] = &ft_light_init,
		[I_SPH] = &ft_sphere_init,
		[I_PLN] = &ft_plane_init,
		[I_SQR] = &ft_square_init,
		[I_CYL] = &ft_cylinder_init,
		[I_TRI] = &ft_triangle_init,
	};

	if (id != -1)
		return (functs[id]);
	return (NULL);
}
