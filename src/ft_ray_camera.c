/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ray_camera.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 12:33:28 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/16 19:04:19 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_cray_plane(t_plane *pln, t_raydata *rdata)
{
	double		time;
	t_vec		hit;

	time = (ft_dotp(ft_vec_sub(rdata->ray.origin, pln->prop.pivot),
			pln->prop.dir)) / ft_dotp(rdata->ray.direction, pln->prop.dir);
	if (time < 0)
		return (0);
	hit = ft_vec_add(rdata->ray.origin,
			ft_vec_scale(rdata->ray.direction, time));
/* 	if (ft_vec_length(hit, rdata->ray.origin) < ft_vec_length(rdata->hit,
		rdata->ray.origin) || ft_vec_length(rdata->hit, rdata->ray.origin) == 0)
	{
		rdata->hit = hit;
		rdata->col = pln->col;
		return (1);
	} */
	return (0);
}

int		ft_cray_tri_in(t_trngl *tri, t_vec normal, t_vec hit)
{
	t_vec	edge;
	t_vec	check;

	check = ft_crossp(ft_vec_sub(tri->p2, tri->p1), ft_vec_sub(hit, tri->p1));
	if (ft_dotp(normal, check) < 0)
		return (0);
	check = ft_crossp(ft_vec_sub(tri->p3, tri->p2), ft_vec_sub(hit, tri->p2));
	if (ft_dotp(normal, check) < 0)
		return (0);
	check = ft_crossp(ft_vec_sub(tri->p1, tri->p3), ft_vec_sub(hit, tri->p3));
	if (ft_dotp(normal, check) < 0)
		return (0);
	return (1);
}

int		ft_cray_triangle(t_trngl *tri, t_raydata *rdata)
{
	t_vec		normal;
	double		time;
	double		denom;
	t_vec		hit;

	normal = ft_crossp(ft_vec_sub(tri->p2, tri->p1),
			ft_vec_sub(tri->p3, tri->p1));
	denom = ft_dotp(normal, tri->p1);
	time = -(ft_dotp(normal, rdata->ray.origin) + denom) /
			ft_dotp(normal, rdata->ray.direction);
	if (time < 0)
		return (0);
	hit = ft_vec_add(rdata->ray.origin,
			ft_vec_scale(rdata->ray.direction, time));
	if (ft_cray_tri_in(tri, normal, hit))
		if (ft_vec_length(hit, rdata->ray.origin) < ft_vec_length(rdata->hit, rdata->ray.origin)
				|| ft_vec_length(rdata->hit, rdata->ray.origin) == 0)
		{
			rdata->hit = hit;
			rdata->col = tri->col;
			return (1);
		}
	return (0);
}

int		ft_lray_sphere(t_sphere *sphere, t_raydata *rdata)
{
	double		length;
	double		coll_t;
	t_vec		r_coll;
	double		intersect_t;

	intersect_t = ft_dotp(ft_vec_sub(sphere->prop.pivot, rdata->ray.origin),
					rdata->ray.direction);
	r_coll = ft_vec_add(rdata->ray.origin,
			ft_vec_scale(rdata->ray.direction, intersect_t));
	length = ft_vec_length(r_coll, sphere->prop.pivot);
	if (length >= 0 && length <= (sphere->diameter / 2))
		return (1);
	return (0);
}

t_vec	ft_sphere_normal(t_sphere *sphere, t_vec r_coll)
{
	double	hitlen;
	double	spherelen;

	hitlen = ft_vec_length(ft_vec_init(0, 0, 0), r_coll);
	spherelen = ft_vec_length(ft_vec_init(0, 0, 0), sphere->prop.pivot);
	if (hitlen > spherelen)
		return (ft_vec_sub(sphere->prop.pivot, r_coll));
	return (ft_vec_sub(r_coll, sphere->prop.pivot));
}

int		ft_cray_sphere(t_sphere *sphere, t_raydata *rdata)
{
	double		intersect_t;
	t_vec		r_coll;
	double		length;
	double		coll_t;

	intersect_t = ft_dotp(ft_vec_sub(sphere->prop.pivot, rdata->ray.origin),
					rdata->ray.direction);
	if (intersect_t < 0)
		return (0);
	r_coll = ft_vec_add(rdata->ray.origin, ft_vec_scale(rdata->ray.direction, intersect_t));
	length = ft_vec_length(r_coll, sphere->prop.pivot);
	if (length > (sphere->diameter / 2))
		return (0);
	coll_t = intersect_t - sqrt(pow(sphere->diameter / 2, 2)
		- pow(length, 2));
	r_coll = ft_vec_add(rdata->ray.origin, ft_vec_scale(rdata->ray.direction, coll_t));
	if (ft_vec_length(rdata->ray.origin, r_coll) < ft_vec_length(rdata->ray.origin, rdata->hit)
		|| ft_vec_length(rdata->ray.origin, rdata->hit) == 0)
	{
		rdata->hit = r_coll;
		rdata->normal = ft_sphere_normal(sphere, r_coll);
		rdata->col = sphere->col;
		return (1);
	}
	return (0);
}

int		ft_loop_sphere(t_data *data, t_raydata *rdata, int raytype)
{
	t_sphere	*root;
	int			ret;

	root = data->sph;
	ret = 0;
	while (data->sph)
	{
		if (raytype == CAMERA_RAY)
			ret = ft_cray_sphere(data->sph, rdata);
		if (raytype == LIGHT_RAY)
		{
			ret = ft_lray_sphere(data->sph, rdata);
			if (ret == 1)
				break ;
		}
		data->sph = data->sph->next;
	}
	data->sph = root;
	return (ret);
}

int		ft_loop_triangle(t_data *data, t_raydata *rdata, int raytype)
{
	t_trngl		*root;
	int			ret;

	root = data->tri;
	ret = 0;
	while (data->tri)
	{
//		printf("I am looking for tri's\n");
		if (raytype == CAMERA_RAY)
			ret = ft_cray_triangle(data->tri, rdata);
		if (raytype == LIGHT_RAY)
		{
//			ret = ft_lray_sphere(data->tri, rdata);
			if (ret == 1)
				break ;
		}
		data->tri = data->tri->next;
	}
	data->tri = root;
	return (ret);
}

int		ft_loop_plane(t_data *data, t_raydata *rdata, int raytype)
{
	t_plane		*root;
	int			ret;

	root = data->pln;
	ret = 0;
	while (data->pln)
	{
//		printf("I am looking for pln's\n");
		if (raytype == CAMERA_RAY)
			ret = ft_cray_plane(data->pln, rdata);
		if (raytype == LIGHT_RAY)
		{
//			ret = ft_lray_sphere(data->pln, rdata);
			if (ret == 1)
				break ;
		}
		data->pln = data->pln->next;
	}
	data->pln = root;
	return (ret);
}
