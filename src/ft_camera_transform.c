/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_camera_transform.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 11:34:58 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/14 16:13:23 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		ft_cam_rot_z(t_vec pos, t_vec rot)
{
	pos.x += pos.x * cos(rot.y * (M_PI / 180));
	pos.x += pos.y * -sin(rot.y * (M_PI / 180));
	pos.y += pos.x * sin(rot.y * (M_PI / 180));
	pos.y += pos.y * cos(rot.y * (M_PI / 180));
	return (pos);
}

t_vec		ft_cam_rot_y(t_vec pos, t_vec rot)
{
	pos.x += pos.x * cos(rot.y * (M_PI / 180));
	pos.x += pos.z * sin(rot.y * (M_PI / 180));
	pos.z += pos.x * -sin(rot.y * (M_PI / 180));
	pos.z += pos.z * cos(rot.y * (M_PI / 180));
	return (pos);
}

t_vec		ft_cam_rot_x(t_vec pos, t_vec rot)
{
	pos.y = pos.y * cos(rot.x * (M_PI / 180));
	pos.y += pos.z * -sin(rot.x * (M_PI / 180));
	pos.z = pos.y * sin(rot.x * (M_PI / 180));
	pos.z += pos.z * cos(rot.x * (M_PI / 180));
	return (pos);
}

t_vec		ft_camera_transform(t_data *data, t_vec cam_p, t_prop transform)
{
	t_vec	new;

	if (transform.rot.x)
		new = ft_cam_rot_x(cam_p, transform.rot);
	if (transform.rot.y)
		new = ft_cam_rot_y(cam_p, transform.rot);
	if (transform.rot.z)
		new = ft_cam_rot_z(cam_p, transform.rot);
	if (transform.trans.x)
		new.x += transform.trans.x;
	if (transform.trans.y)
		new.y += transform.trans.y;
	if (transform.trans.z)
		new.z += transform.trans.z;
	return (new);
}
