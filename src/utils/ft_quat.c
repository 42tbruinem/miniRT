/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_quat.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 15:27:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/22 16:25:31 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_quat_print(t_quat quat, char *name)
{
	printf("quat: %s\n", name);
	printf("W:%f, X:%f, Y:%f, Z:%f\n", quat.w, quat.x, quat.y, quat.z);
}

double		ft_quat_length(t_quat a)
{
	double	len;

	len = a.w * a.w;
	len += a.x * a.x;
	len += a.y * a.y;
	len += a.z * a.z;
	return (sqrt(len));
}

t_quat		ft_quat_normalize(t_quat a)
{
	double	len;

	len = ft_quat_length(a);
	a.w /= len;
	a.x /= len;
	a.y /= len;
	a.z /= len;
	return (a);
}

t_quat		ft_quat_init(double w, double x, double y, double z)
{
	t_quat	new;

	new.w = w;
	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_quat		ft_quat_new(double x, double y, double z, double angle)
{
	t_quat	new;

	angle = ft_deg2rad(angle / 2);
	new.w = cos(angle);
	new.x = x * sin(angle);
	new.y = y * sin(angle);
	new.z = z * sin(angle);
	return (new);
}

t_matrix	ft_quat_to_matrix(t_quat quat)
{
	t_matrix	new;
	double		w;
	double		x;
	double		y;
	double		z;

	w = quat.w;
	x = quat.x;
	y = quat.y;
	z = quat.z;
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

t_quat		ft_quat_scale(t_quat a, double scalar)
{
	a.w *= scalar;
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;
	return (a);
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

t_quat		ft_quat_lookat(t_vec to, t_vec from)
{
/* 	double	sum;
	t_vec	up;

	sum = sqrt(ft_dotp(to, to) * ft_dotp(from, from)) + ft_dotp(to, from);
	if (sum < 1.e-6f * (sqrt(ft_dotp(to, to) * ft_dotp(from, from))))
	{
		sum = 0;
		up = (ft_abs(to.x) > ft_abs(to.z)) ? ft_vec_init(-to.y, to.x, 0)
									: ft_vec_init(0, -to.z, to.y);
	}
	else
		up = ft_crossp(to, from);
	return (ft_quat_normalize(ft_quat_init(sum, up.x, up.y, up.z))); */
/* 	double	angle;
	t_vec	up;

	angle = acos(ft_dotp(ft_vec_normalize(to), ft_vec_normalize(from)));
	up = ft_vec_normalize(ft_crossp(to, from));
//	ft_quat_print(ft_quat_new(up.x, up.y, up.z, ft_rad2deg(angle)), "lookat quat");
	return (ft_quat_new(up.x, up.y, up.z, ft_rad2deg(angle))); */
	double	angle;
	double	length;
	t_vec	axis;
	t_quat	lookat;

	angle = acos(ft_dotp(ft_vec_normalize(to), ft_vec_normalize(from)));
	axis = ft_vec_normalize(ft_crossp(to, from));
	length = ft_vec_length(ft_vec_init(0, 0, 0), axis);
	printf("length of up vector %f\n", length);
	if (length > -EPSILON && length < EPSILON)
	{
		printf("pepsi land\n");
		axis = ft_vec_init(0, 0, -1);
	}
	lookat = ft_quat_new(axis.x, axis.y, axis.z, ft_rad2deg(angle * 2));
	return (lookat);
}

t_matrix	ft_newrotate(t_data *data, t_quat new)
{
	t_quat	res;

	data->cams->quat = ft_quat_mult(new, data->cams->quat);
//	data->cams->quat = ft_quat_normalize(data->cams->quat);
	return (ft_quat_to_matrix(data->cams->quat));
}
