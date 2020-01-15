/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cam_to_w.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:57:45 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 11:50:51 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_vec_to_mat(t_vec vec, t_matrix new)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			new[i][j] = 0;
			j++;
		}
		i++;
	}
	new[0][0] = vec.x;
	new[1][0] = vec.y;
	new[2][0] = vec.z;
	new[3][0] = 1;
}

t_vec		ft_mat_to_vec(t_matrix mat)
{
	t_vec new;

	new.x = mat[0][0];
	new.y = mat[1][0];
	new.z = mat[2][0];
	new.t = 1;
	return (new);
}
/* 
Get camera right, up and forward
construct a matrix based on those and the camera's starting position
 */
void	ft_lookat(t_cam *cam)
{
	t_vec	cam_r;
	t_vec	cam_f;
	t_vec	cam_u;
	t_vec	tmp;

	cam_f = cam->prop.dir;
	if (cam_f.y != 1)
		tmp = ft_vec_init(0, 1, 0);
	else
		tmp = ft_vec_init(0, 0, -1);
	cam_r = ft_crossp(tmp, cam_f);
	cam_u = ft_crossp(cam_f, cam_r);
	cam->c2w[0][0] = cam_r.x;
	cam->c2w[1][0] = cam_r.y;
	cam->c2w[2][0] = cam_r.z;
	cam->c2w[0][1] = cam_u.x;
	cam->c2w[1][1] = cam_u.y;
	cam->c2w[2][1] = cam_u.z;
	cam->c2w[0][2] = cam_f.x;
	cam->c2w[1][2] = cam_f.y;
	cam->c2w[2][2] = cam_f.z;
	cam->c2w[0][3] = cam->prop.pivot.x;
	cam->c2w[1][3] = cam->prop.pivot.y;
	cam->c2w[2][3] = cam->prop.pivot.z;
	cam->c2w[3][3] = 1;
}

void	ft_c2w_update(t_cam *cam)
{
	t_matrix	tmp1;
	t_matrix	tmp2;

//	ft_matrix_dup(cam->c2w, tmp2);
//	ft_matrix_rot_x(cam->prop.rot.x, tmp1);
//	ft_matrix_mult(tmp1, tmp2, cam->c2w);
//	ft_matrix_dup(cam->c2w, tmp2);
//	ft_matrix_rot_y(cam->prop.rot.y, tmp1);
//	ft_matrix_mult(tmp1, tmp2, cam->c2w);
//	ft_matrix_dup(cam->c2w, tmp2);
//	ft_matrix_rot_z(cam->prop.rot.z, tmp1);
//	ft_matrix_mult(tmp1, tmp2, cam->c2w);
	ft_matrix_print(cam->c2w);
	ft_matrix_dup(cam->c2w, tmp2);
	ft_matrix_t(cam->prop.trans, tmp1);
	ft_matrix_print(tmp1);
	ft_matrix_mult(tmp1, tmp2, cam->c2w);
	ft_matrix_print(cam->c2w);
}

t_vec		ft_c2w_apply(t_vec old, t_cam *cam)
{
	t_matrix	tmp;
	t_matrix	fnl;
	t_vec		new;

//	printf("original vector\n");
//	printf("old, %f, %f, %f\n", old.x, old.y, old.z);
	ft_vec_to_mat(old, tmp);
//	printf("converted to matrix:\n");
//	ft_matrix_print(tmp);
	ft_matrix_mult(tmp, cam->c2w, fnl);
//	printf("final matrix with transforms applied\n");
//	ft_matrix_print(fnl);
	new = ft_mat_to_vec(fnl);
//	printf("matrix converted back to vector:\n");
//	printf("old: %f, %f, %f\n", old.x, old.y, old.z);
	return (new);
}
