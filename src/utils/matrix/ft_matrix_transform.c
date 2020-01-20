/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix_transform.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:23:57 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/18 18:20:06 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		ft_deg2rad(double rotation)
{
	return (rotation * (M_PI / 180));
}

t_matrix	ft_matrix_s(t_vec s)
{
	t_matrix	new;

	new.r1 = ft_vec_init(s.x, 0, 0);
	new.r2 = ft_vec_init(0, s.y, 0);
	new.r3 = ft_vec_init(0, 0, s.z);
	return (new);
}

t_matrix	ft_matrix_rot_z(double rotation)
{
	t_matrix	new;
	double		rot;

	rot = ft_deg2rad(rotation);
	new.r1 = ft_vec_init(cos(rot), -sin(rot), 0);
	new.r2 = ft_vec_init(sin(rot), cos(rot), 0);
	new.r3 = ft_vec_init(0, 0, 1);
	ft_matrix_print(new, "rot z");
	return (new);
}

t_matrix	ft_matrix_rot_y(double rotation)
{
	t_matrix	new;
	double		rot;

	rot = ft_deg2rad(rotation);
	new.r1 = ft_vec_init(cos(rot), 0, sin(rot));
	new.r2 = ft_vec_init(0, 1, 0);
	new.r3 = ft_vec_init(-sin(rot), 0, cos(rot));
	ft_matrix_print(new, "rot y");
	return (new);
}

t_matrix	ft_matrix_rot_x(double rotation)
{
	t_matrix	new;
	double		rot;

	rot = ft_deg2rad(rotation);
	new.r1 = ft_vec_init(1, 0, 0);
	new.r2 = ft_vec_init(0, cos(rot), -sin(rot));
	new.r3 = ft_vec_init(0, sin(rot), cos(rot));
	ft_matrix_print(new, "rot x");
	return (new);
}
