/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ray_camera.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 12:33:28 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/04 12:33:28 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//collision might be a negative number because of sqrt??

void	ft_cray_sphere(t_ray ray, void *obj, unsigned int *col, t_vec *hit)
{
	double		intersect_t;
	t_sphere	*sphere;
	t_vec		r_coll;
	double		length;
	double		coll_t;

	sphere = (t_sphere *)obj;
	intersect_t =	ft_dotp(ft_vec_sub(sphere->prop.pivot, ray.origin),
					ray.direction);
	r_coll = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, intersect_t));
	length = ft_vec_length(r_coll, sphere->prop.pivot);
	if (length > (sphere->diameter / 2))
		return ;
	coll_t = intersect_t - sqrt(pow(sphere->diameter / 2, 2) - pow(length, 2));
	r_coll = ft_vec_add(ray.origin, ft_vec_scale(ray.direction, coll_t));
	if (ft_vec_length(ray.origin, r_coll) < ft_vec_length(ray.origin, *hit)
		|| ft_vec_length(ray.origin, *hit) == 0)
	{
		*col = ft_col_tohex(sphere->col);
		*hit = r_coll;
	}
}
