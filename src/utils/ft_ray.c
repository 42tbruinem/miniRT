/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ray.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 15:53:18 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/18 17:52:59 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**first convert to NDC ((x/y + 0.5) / width/height)
**then convert to ScreenSpace (change the range to -1, 1 from 0, 1)
**X: (2 * NDCx) - 1
**Y: (1 - (2 * NDCy))
*/

/*
**then when we add the fov and the camera orientation
**we can convert it into worldspace
*/

/*
**to the center of the screen, the length is X
**that line, together with the point at screenwidth,screenheight / 2 (A)
**forms a triangle.
**made up of FOV + 90 + (90 - FOV)
**we know the length of the side: A (screenwidth / 2)
*/

void	ft_cameraray(t_data *data, t_raydata *rdata)
{
	int		obj;
	t_vec	hit;
	t_loopf	funct;

	obj = SPH;
	rdata->hit = rdata->ray.origin;
	while (1)
	{
		funct = ft_loop_funct(obj);
		if (!funct)
			return ;
		funct(data, rdata, CAMERA_RAY);
		obj++;
	}
}

int		ft_lightray_intersect(t_data *data, t_raydata *rdata)
{
	int			ret;
	t_loopf		funct;
	int			obj;

	obj = SPH;
	ret = 0;
	while (1)
	{
		funct = ft_loop_funct(obj);
		if (!funct || ret == 1)
			break ;
		ret = funct(data, rdata, LIGHT_RAY);
		obj++;
	}
	return (ret);
}

int		ft_lightray(t_data *data, t_raydata *rdata)
{
	t_light		*root;
	int			ret;

	root = data->light;
	while (data->light)
	{
		rdata->dist = ft_vec_length(rdata->hit, data->light->prop.pivot);
		rdata->ray.origin = rdata->hit;
		rdata->ray.direction = ft_vec_sub(data->light->prop.pivot, rdata->hit);
//		if (ft_lightray_intersect(data, rdata) == 0)
//			rdata->col = ft_col_mult(rdata->col, data->light->col, data->light->bright *  (40 / (ft_dotp(rdata->ray.direction, rdata->normal))));
//		return (color_mul(hit->color, light.color, intensity));
		data->light = data->light->next;
	}
	data->light = root;
	return (ret);
}

t_ray	ft_ray_init(t_data *data, int x, int y)
{
	double		ratio;
	t_ray		ray;

	if (data->width > data->height)											//get the ratio to scale x or y pixels up as needed
		ratio = (double)data->width / (double)data->height;
	if (data->height > data->width)
		ratio = (double)data->height / (double)data->width;
	ray.direction.x = (2.0 * (x + 0.5) / (double)data->width - 1.0);		//set the X direction for the ray
	if (data->width > data->height)
		ray.direction.x *= ratio;
	ray.direction.y = 1.0 - 2.0 * (y + 0.5) / (double)data->height;			//set the Y direction for the ray
	if (data->height > data->width)
		ray.direction.y *= ratio;
	ray.direction.z = 1;													//set the Z direction for the ray
	ray.direction = ft_vec_scale(ray.direction,								//we scale the X and Y based on the tan of the FOV / 2 (since we keep the distance to the camera as 1(Z))
					tan(((double)data->cams->fov / 2) * (M_PI / 180)));
	ray.direction.z = -1;
//	ft_matrix_print(data->cams->c2w, "cam2world");
//	ft_vec_print(ray.direction, "old dir");
	ray.direction = ft_matrix_apply(data->cams->c2w, ray.direction);		//this should apply the necessary rotations and translations to the ray
	ray.origin = data->cams->prop.pivot;									//this sets the ray origin to the camera's position
	ray.direction = ft_normalize(ray.direction);							//then we normalize, ta -da
//	ft_vec_print(ray.direction, "new dir");
	return (ray);
}
