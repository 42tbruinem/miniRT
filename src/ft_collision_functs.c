/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_collision_functs.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 13:53:31 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/04 13:53:31 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_collf		ft_coll_funct(int id)
{
	static const t_collf functs[5] = {
		[C_SPH] = &ft_cray_sphere,
/* 		[C_PLN] = &ft_cray_plane,
		[C_SQR] = &ft_cray_square,
		[C_CYL] = &ft_cray_cylinder,
		[C_TRI] = &ft_cray_triangle, */
	};

	if (id != -1)
		return (functs[id]);
	return (NULL);
}
