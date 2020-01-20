/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_quat.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 15:27:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/20 20:06:08 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_quat		ft_quat_init(double w, double x, double y, double z)
{
	t_quat	new;

	new.w = w;
	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_quat		ft_quat_new(t_vec axis, double angle)
{
	t_quat	new;
//	double	a;

//
	new.w = cos(angle);
	new.x = axis.x * sin(angle);
	new.y = axis.y * sin(angle);
	new.z = axis.z * sin(angle);
	return (new);
}

t_matrix	ft_quat_to_matrix(double w, double x, double y, double z)
{
	t_matrix	new;

	new.r1.x = w * w + x * x - y * y - z * z;
	new.r1.y = 2 * x * y - 2 * w * z;
	new.r1.z = 2 * x * z + 2 * w * y;
	new.r2.x = 2 * x * y + 2 * w * z;
	new.r2.y = w * w - x * x + y * y - z * z;
	new.r2.z = 2 * y * z + 2 * w * x;
	new.r3.x = 2 * x * z - 2 * w * y;
	new.r3.y = 2 * y * z - 2 * w * x;
	new.r3.z = w * w - x * x - y * y + z * z;
	return (new);
}

t_quat		ft_quat_mult(t_quat a, t_quat b)
{
	t_quat	new;

	new.w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	new.x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y;
	new.y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x;
	new.z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w;
	return (new);
}
