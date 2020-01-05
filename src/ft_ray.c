/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ray.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/04 15:53:18 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/05 17:27:08 by tbruinem      ########   odam.nl         */
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

t_vec	ft_ray_direction(t_data *data, int x, int y)
{
	double		ratio;
	t_vec		ray_dir;

	if (data->width > data->height)
		ratio = data->width / data->height;
	else
		ratio = data->height / data->width;
	ray_dir.x = (2 * ((x + 0.5) / data->width) - 1);
	if (data->width > data->height)
		ray_dir.x *= ratio;
	ray_dir.y = 1 - (2 * ((y + 0.5) / data->height));
	if (data->height > data->width)
		ray_dir.y *= ratio;
	ray_dir.z = 1;
	ray_dir = ft_vec_scale(ray_dir, tan((data->cams->fov / 2) * (M_PI / 180)));
	ray_dir.z = -1;
	ray_dir = ft_vec_sub(ray_dir, ft_vec_init(0, 0, 0));
	ray_dir = ft_normalize(ray_dir);
//	printf("x : %d | y: %d\n", x, y);
//	printf("X %f\n", ray_dir.x);
//	printf("Y %f\n", ray_dir.y);
//	printf("Z %f\n", ray_dir.z);
	return (ray_dir);
}
