/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vector_advanced.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 15:54:05 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/14 18:49:27 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	ft_normalize(t_vec vector)
{
	double	length;

	length = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	if (length == 0)
		return (ft_vec_init(0, 0, 0));
	vector.x /= length;
	vector.y /= length;
	vector.z /= length;
	return (vector);
}

double	ft_vec_length(t_vec a, t_vec b)
{
	double	x;
	double	y;
	double	z;
	double	ret;

	x = pow(a.x - b.x, 2);
	y = pow(a.y - b.y, 2);
	z = pow(a.z - b.z, 2);
	ret = sqrt(x + y + z);
	return (ret);
}

double	ft_dotp(t_vec a, t_vec b)
{
	double	x;
	double	y;
	double	z;

	x = a.x * b.x;
	y = a.y * b.y;
	z = a.z * b.z;
	return (x + y + z);
}

t_vec	ft_crossp(t_vec a, t_vec b)
{
	t_vec	new;

	new.x = a.y * b.z - a.z * b.y;
	new.y = a.z * b.x - a.x * b.z;
	new.z = a.x * b.y - a.y * b.x;
	return (new);
}
