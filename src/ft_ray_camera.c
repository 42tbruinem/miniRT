/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ray_camera.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 12:33:28 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 13:51:53 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** when looking for a camera-ray intersection with an object, we want to know:
** - the place where it's hit
*/

/*
** when looking for a light-ray intersection with an object, we want to know:
** - the place where it's hit
*/

int	ft_cray_sphere(t_ray ray, t_sphere *sphere, t_vec *hit)
{
	double		intersect_t;
	t_vec		r_coll;
	double		length;
	double		coll_t;

	intersect_t = ft_dotp(ft_vec_sub(sphere->prop.pivot, ray.origin),
					ray.direction);
	if (intersect_t < 0)
		return (0);
	r_coll = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, intersect_t));
	length = ft_vec_length(r_coll, sphere->prop.pivot);
	if (length > (sphere->diameter / 2))
		return (0);
	coll_t = intersect_t - sqrt(pow(sphere->diameter / 2, 2)
		- pow(length, 2));
	r_coll = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, coll_t));
	if (ft_vec_length(ray.origin, r_coll) < ft_vec_length(ray.origin, *hit)
		|| ft_vec_length(ray.origin, *hit) == 0)
	{
		*hit = r_coll;
		return (1);
	}
	return (0);
}

void	ft_sphere_loop(t_data *data, t_vec *hit, t_ray ray, t_col *col)
{
	t_sphere	*root;

	root = data->sph;
	while (data->sph)
	{
		if (ft_cray_sphere(ray, data->sph, hit))
			*col = data->sph->col;
		data->sph = data->sph->next;
	}
	data->sph = root;
}
