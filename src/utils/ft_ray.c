/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ray.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 15:53:18 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 14:27:34 by tbruinem      ########   odam.nl         */
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

void	ft_ray_coll(t_data *data, t_ray ray, t_col *col)
{
	int		i;
	t_vec	hit;
	t_collf	funct;

	i = SPH;
	hit = ray.origin;
	while (1)
	{
		funct = ft_coll_funct(i);
		if (!funct)
			return ;
		funct(data, &hit, ray, col);
		i++;
	}
}

t_ray	ft_ray_init(t_data *data, int x, int y)
{
	double		ratio;
	t_ray		ray;

	if (data->width > data->height)
		ratio = (double)data->width / (double)data->height;
	if (data->height > data->width)
		ratio = (double)data->height / (double)data->width;
	ray.direction.x = (2.0 * ((x + 0.5) / (double)data->width) - 1.0);
	if (data->width > data->height)
		ray.direction.x *= ratio;
	ray.direction.y = 1.0 - (2.0 * ((y + 0.5) / (double)data->height));
	if (data->height > data->width)
		ray.direction.y *= ratio;
	ray.direction.z = 1;
//	if (x % 50 == 0)
//		printf("ray origin:\n");
//	ray.origin = data->cams->prop.pivot;
//	printf("rd old: %f, %f, %f\n", ray.origin.x, ray.origin.y, ray.origin.z);
//	ray.origin = ft_c2w_apply(data->cams->prop.pivot, data->cams);
//	printf("rd new: %f, %f, %f\n", ray.origin.x, ray.origin.y, ray.origin.z);
	ray.direction = ft_vec_scale(ray.direction,
					tan((double)data->cams->fov * (M_PI / 180) / 2));
	ray.origin = ft_c2w_apply(data->cams->prop.pivot, data->cams);
	ray.direction = ft_c2w_apply(ray.direction, data->cams);
	ray.direction = ft_vec_sub(ray.direction, ray.origin);
	ray.direction.z = 1;
	ray.direction = ft_normalize(ray.direction);
//	if (x % 50 == 0)
//		printf("ray direction:\n");
//	ray.direction = ft_c2w_apply(ray.direction, data->cams);
//	ray.direction = ft_normalize(ray.direction);
//	printf("ray direction: %f, %f, %f\n", ray.direction.x, ray.direction.y, ray.direction.z);
//	ray.direction = ft_normalize(ft_vec_sub(ray.direction, ray.origin));
	return (ray);
}
