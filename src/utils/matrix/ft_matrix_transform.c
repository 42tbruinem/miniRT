/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix_transform.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/11 16:23:57 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 11:53:42 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_matrix_s(t_vec s, t_matrix new)
{
	new[0][0] = s.x;
	new[1][1] = s.y;
	new[2][2] = s.z;
	new[3][3] = 1;
}

void		ft_matrix_t(t_vec t, t_matrix new)
{
	new[0][0] = 1;
	new[1][1] = 1;
	new[2][2] = 1;
	new[0][3] = t.x;
	new[1][3] = t.y;
	new[2][3] = t.z;
	new[3][3] = 1;
}

void		ft_matrix_rot_z(double rotation, t_matrix new)
{
	new[0][0] = cos(rotation * (M_PI / 180));
	new[0][1] = -sin(rotation * (M_PI / 180));
	new[1][0] = sin(rotation * (M_PI / 180));
	new[1][1] = cos(rotation * (M_PI / 180));
	new[2][2] = 1;
	new[3][3] = 1;
}

void		ft_matrix_rot_y(double rotation, t_matrix new)
{
	new[0][0] = cos(rotation * (M_PI / 180));
	new[0][2] = sin(rotation * (M_PI / 180));
	new[1][1] = 1;
	new[2][0] = -sin(rotation * (M_PI / 180));
	new[2][2] = cos(rotation * (M_PI / 180));
	new[3][3] = 1;
}

void		ft_matrix_rot_x(double rotation, t_matrix new)
{
	new[0][0] = 1;
	new[1][1] = cos(rotation * (M_PI / 180));
	new[1][2] = -sin(rotation * (M_PI / 180));
	new[2][1] = sin(rotation * (M_PI / 180));
	new[2][2] = cos(rotation * (M_PI / 180));
	new[3][3] = 1;
}
