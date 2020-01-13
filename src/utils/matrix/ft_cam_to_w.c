/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cam_to_w.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:57:45 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/12 13:22:50 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	ft_vec_to_mat(t_vec vec)
{
	t_matrix	new;

	new = ft_matrix_new(4, 1);
	new.mat[0][0] = vec.x;
	new.mat[1][0] = vec.y;
	new.mat[2][0] = vec.z;
	new.mat[3][0] = vec.t;
	return (new);
}

t_vec		ft_mat_to_vec(t_matrix mat)
{
	t_vec new;

	new.x = mat.mat[0][0];
	new.y = mat.mat[1][0];
	new.z = mat.mat[2][0];
	new.t = mat.mat[3][0];
	return (new);
}

t_matrix	ft_mult_and_clean(t_matrix a, t_matrix b)
{
	t_matrix	res;

	res = ft_matrix_mult(a, b);
	ft_matrix_del(a);
	ft_matrix_del(b);
	return (res);
}

t_vec		ft_cam_to_w(t_vec old, t_prop properties)
{
	t_matrix	res;
	t_vec		new;

	res = ft_mult_and_clean(ft_matrix_rot_x(properties.rot.x),
		ft_matrix_rot_y(properties.rot.y));
	res = ft_mult_and_clean(res, ft_matrix_rot_z(properties.rot.z));
	res = ft_mult_and_clean(res, ft_matrix_t(properties.trans));
	res = ft_mult_and_clean(res, ft_vec_to_mat(old));
	new = ft_mat_to_vec(res);
	ft_matrix_del(res);
	return (new);
}
