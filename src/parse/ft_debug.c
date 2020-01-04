/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_debug.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:23:47 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/04 13:19:02 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_res_print(t_data *data)
{
	printf("----RESOLUTION----\n");
	printf("WIDTH: %d\n", data->width);
	printf("HEIGHT: %d\n", data->height);
}

void	ft_amb_print(t_ambient amb)
{
	printf("----AMBIENT------\n");
	printf("STRENGTH: %f\n", amb.bright);
	printf("col: R%d,G%d,B%d\n", amb.col.r,\
			amb.col.g, amb.col.b);
}

void	ft_cam_print(t_cam *cam)
{
	printf("----CAMERA-------\n");
	printf("COORD: X%f,Y%f,Z%f\n", cam->prop.pivot.x,
			cam->prop.pivot.y, cam->prop.pivot.z);
	printf("DIR:   X%f,Y%f,Z%f\n", cam->prop.dir.x,
			cam->prop.dir.y, cam->prop.dir.z);
	printf("FOV: %d\n", cam->fov);
}

void	ft_light_print(t_light *light)
{
	printf("----LIGHT--------\n");
	printf("COORD: X%f,Y%f,Z%f\n", light->prop.pivot.x,
			light->prop.pivot.y, light->prop.pivot.z);
	printf("BRIGHTNESS: %f\n", light->bright);
	printf("col: R%d,G%d,B%d\n", light->col.r,
			light->col.g, light->col.b);
}

void	ft_sph_print(t_sphere *sphere)
{
	printf("----SPHERE-------\n");
	printf("COORD: X%f,Y%f,Z%f\n", sphere->prop.pivot.x,
			sphere->prop.pivot.y, sphere->prop.pivot.z);
	printf("DIAMETER: %f\n", sphere->diameter);
	printf("col: R%d,G%d,B%d\n", sphere->col.r,
			sphere->col.g, sphere->col.b);
}

void	ft_pln_print(t_plane *obj)
{
	printf("----PLANE--------\n");
	printf("COORD: X%f,Y%f,Z%f\n", obj->prop.pivot.x,
			obj->prop.pivot.y, obj->prop.pivot.z);
	printf("ORIENT: X%f,Y%f,Z%f\n", obj->prop.dir.x,
			obj->prop.dir.y, obj->prop.dir.z);
	printf("col: R%d,G%d,B%d\n", obj->col.r,
			obj->col.g, obj->col.b);
}

void	ft_sqr_print(t_square *obj)
{
	printf("----SQUARE-------\n");
	printf("COORD: X%f,Y%f,Z%f\n", obj->prop.pivot.x,
			obj->prop.pivot.y, obj->prop.pivot.z);
	printf("ORIENT: X%f,Y%f,Z%f\n", obj->prop.dir.x,
			obj->prop.dir.y, obj->prop.dir.z);
	printf("SIZE: %f\n", obj->size);
	printf("col: R%d,G%d,B%d\n", obj->col.r,
			obj->col.g, obj->col.b);
}

void	ft_cylndr_print(t_cylndr *obj)
{
	printf("----CYLINDER-----\n");
	printf("COORD: X%f,Y%f,Z%f\n", obj->prop.pivot.x,
			obj->prop.pivot.y, obj->prop.pivot.z);
	printf("ORIENT: X%f,Y%f,Z%f\n", obj->prop.dir.x,
			obj->prop.dir.y, obj->prop.dir.z);
	printf("DIAMETER: %f\n", obj->width);
	printf("HEIGHT: %f\n", obj->height);
	printf("col: R%d,G%d,B%d\n", obj->col.r,
			obj->col.g, obj->col.b);
}

void	ft_tri_print(t_trngl *obj)
{
	printf("----TRIANGLE-----\n");
	printf("P1 X%f,Y%f,Z%f\n", obj->p1.x, obj->p1.y,
			obj->p1.z);
	printf("P2 X%f,Y%f,Z%f\n", obj->p2.x, obj->p2.y,
			obj->p2.z);
	printf("P3 X%f,Y%f,Z%f\n", obj->p3.x, obj->p3.y,
			obj->p3.z);
	printf("col: R%d,G%d,B%d\n", obj->col.r,
			obj->col.g, obj->col.b);
}

void	ft_data_print(t_data *data)
{
	ft_res_print(data);
	ft_amb_print(data->amb);
	ft_cam_print(data->cams);
	ft_light_print(data->light);
	ft_pln_print(data->pln);
	ft_sph_print(data->sph);
	ft_sqr_print(data->sqr);
	ft_cylndr_print(data->cyl);
	ft_tri_print(data->tri);
}
