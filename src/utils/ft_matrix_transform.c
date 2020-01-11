/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix_transform.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:23:57 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/11 16:44:48 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_matrix_s(t_vec s)
{
	t_matrix	new;

	new = ft_matrix_new(4, 4);
	ft_matrix_init(&new, 0);
	new.mat[0][0] = s.x;
	new.mat[1][1] = s.y;
	new.mat[2][2] = s.z;
	new.mat[3][3] = 1;
	return (new);
}

t_matrix	ft_matrix_t(t_vec t)
{
	t_matrix	new;

	new = ft_matrix_new(4, 4);
	ft_matrix_init(&new, 0);
	new.mat[0][0] = 1;
	new.mat[1][1] = 1;
	new.mat[2][2] = 1;
	new.mat[0][3] = t.x;
	new.mat[1][3] = t.y;
	new.mat[2][3] = t.z;
	new.mat[3][3] = 1;
	return (new);
}

t_matrix	ft_matrix_rot_z(double rotation)
{
	t_matrix	new;

	new = ft_matrix_new(4, 4);
	ft_matrix_init(&new, 0);
	new.mat[0][0] = cos(rotation * (M_PI / 180));
	new.mat[0][1] = -sin(rotation * (M_PI / 180));
	new.mat[1][0] = sin(rotation * (M_PI / 180));
	new.mat[1][1] = cos(rotation * (M_PI / 180));
	new.mat[2][2] = 1;
	new.mat[3][3] = 1;
	return (new);
}

t_matrix	ft_matrix_rot_y(double rotation)
{
	t_matrix	new;

	new = ft_matrix_new(4, 4);
	ft_matrix_init(&new, 0);
	new.mat[0][0] = cos(rotation * (M_PI / 180));
	new.mat[0][2] = sin(rotation * (M_PI / 180));
	new.mat[1][1] = 1;
	new.mat[2][0] = -sin(rotation * (M_PI / 180));
	new.mat[2][2] = cos(rotation * (M_PI / 180));
	new.mat[3][3] = 1;
	return (new);
}

t_matrix	ft_matrix_rot_x(double rotation)
{
	t_matrix	new;

	new = ft_matrix_new(4, 4);
	ft_matrix_init(&new, 0);
	new.mat[0][0] = 1;
	new.mat[1][1] = cos(rotation * (M_PI / 180));
	new.mat[1][2] = -sin(rotation * (M_PI / 180));
	new.mat[2][1] = sin(rotation * (M_PI / 180));
	new.mat[2][2] = cos(rotation * (M_PI / 180));
	new.mat[3][3] = 1;
	return (new);
}
