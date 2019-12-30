/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_debug.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:23:47 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 19:02:28 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_res_print(t_data *data)
{
	printf("----RESOLUTION----\n");
	printf("WIDTH: %d\n", data->width);
	printf("HEGHT: %d\n", data->height);
}

void	ft_amb_print(t_ambient *amb)
{
	printf("----AMBIENT------\n");
	printf("STRENGTH: %f\n", amb->bright);
	printf("COLOR: R%d,G%d,B%d\n", amb->color.red, amb->color.green, amb->color.blue);
}

void	ft_cam_print(t_cam *cam)
{
	printf("----CAMERA-------\n");
	printf("COORD: X%f,Y%f,Z%f\n", cam->prop.pivot.x, cam->prop.pivot.y, cam->prop.pivot.z);
	printf("DIR:   X%f,Y%f,Z%f\n", cam->dir.x, cam->dir.y, cam->dir.z);
	printf("FOV: %d\n", cam->fov);
}

void	ft_light_print(t_light *light)
{
	printf("----LIGHT--------\n");
	printf("COORD: X%f,Y%f,Z%f\n", light->prop.pivot.x, light->prop.pivot.y, light->prop.pivot.z);
	printf("BRIGHTNESS: %f\n", light->bright);
	printf("COLOR: R%d,G%d,B%d\n", light->color.red, light->color.green, light->color.blue);
}

void	ft_sph_print(t_sphere *sphere)
{
	printf("----SPHERE-------\n");
	printf("COORD: X%f,Y%f,Z%f\n", sphere->prop.pivot.x, sphere->prop.pivot.y, sphere->prop.pivot.z);
	printf("DIAMETER: %f\n", sphere->diameter);
	printf("COLOR: R%d,G%d,B%d\n", sphere->color.red, sphere->color.green, sphere->color.blue);
}

void	ft_pln_print(t_plane *obj)
{
	printf("----PLANE--------\n");
	printf("COORD: X%f,Y%f,Z%f\n", obj->prop.pivot.x, obj->prop.pivot.y, obj->prop.pivot.z);
	printf("COLOR: R%d,G%d,B%d\n", obj->color.red, obj->color.green, obj->color.blue);

}


void	ft_data_print(t_data *data)
{


}