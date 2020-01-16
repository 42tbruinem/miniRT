/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_loop_functs.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 13:53:31 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/16 11:37:11 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_loopf		ft_loop_funct(int id)
{
	static const t_loopf functs[10] = {
		[SPH] = &ft_loop_sphere,
		[PLN] = &ft_loop_plane,
//		[SQR] = &ft_loop_square,
//		[CYL] = &ft_loop_cylinder,
		[TRI] = &ft_loop_triangle,
	};

	return (functs[id]);
}
