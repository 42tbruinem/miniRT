/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ray.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 15:53:18 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/06 17:13:57 by tbruinem      ########   odam.nl         */
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
to the center of the screen, the length is X
that line, together with the point at screenwidth,screenheight / 2 (A)
forms a triangle.
made up of FOV + 90 + (90 - FOV)
we know the length of the side: A (screenwidth / 2)
*/

void	ft_ray_coll(t_data *data, t_ray ray, unsigned int *col)
{
	int		i;
	t_vec	hit;
	t_collf	funct;
	void	*objects[8];

	i = SPH;
	hit = ray.origin;
	ft_object_get(objects, data);
	while (objects[i])
	{
		funct = ft_coll_funct(i);
		while (objects[i])
		{
			if (!funct)
				return ;
			funct(ray, objects[i], col, &hit);
			objects[i] = ft_object_iter(objects[i], i);
		}
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
	ray.direction.x = (2 * ((x + 0.5) / data->width) - 1);
	if (data->width > data->height)
		ray.direction.x *= ratio;
	ray.direction.y = 1 - (2 * ((y + 0.5) / data->height));
	if (data->height > data->width)
		ray.direction.y *= ratio;
	ray.direction.z = 1;
	ray.origin = ft_vec_init(0, 0, 0);
	ray.direction = ft_vec_scale(ray.direction,
					tan((data->cams->fov / 2) * (M_PI / 180)));
	ray.direction.z = 1;
	ray.direction = ft_vec_sub(ray.direction, ray.origin);
	ray.direction = ft_normalize(ray.direction);
	return (ray);
}
