/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_render.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 12:57:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/04 17:11:23 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* void			ft_pixel_put(t_data *data, int x, int y, unsigned int col)
{
	mlx_pixel_put(data->mlx.data, data->mlx.window, x, y, col);
} */

void			**ft_objects_get(t_data *data)
{
	void		**objects;

	objects = malloc(sizeof(void *) * 8);
	if (objects == NULL)
		return (objects);
	objects[0] = data->cyl;
	objects[1] = data->pln;
	objects[2] = data->sph;
	objects[3] = data->sqr;
	objects[4] = data->tri;
	objects[5] = 0;
	return (objects);
}

void	*ft_object_iter(void *obj, int i)
{
	if (i == 0)
		return (((t_cylndr *)obj)->next);
	if (i == 1)
		return (((t_plane *)obj)->next);
	if (i == 2)
		return (((t_sphere *)obj)->next);
	if (i == 3)
		return (((t_square *)obj)->next);
	if (i == 4)
		return (((t_trngl *)obj)->next);
	return (NULL);
}	

int		ft_cray_fire(t_data *data, t_ray ray, unsigned int *col)
{
	int				hit;
	int				i;
	void			**objects;
	t_collf			funct;	

	hit = 0;
	i = 0;
	objects = ft_objects_get(data);
	if (!objects)
		return (ERR_MEM);
	while (hit == 0 && objects[i])
	{
		funct = ft_coll_funct(i);
		if (!funct)
			return (ERR_MEM);
		while (objects[i] && hit == 0)
		{
			hit = funct(ray, objects[i], col);
			objects[i] = ft_object_iter(objects[i], i);
		}
		i++;
	}
	return (0);
}

int		ft_render(t_data *data)
{
	int				x;
	int				y;
	unsigned int	col;
	t_ray			ray;
	int				error;

	y = 0;
	while (y <= data->height)
	{
		x = 0;
		while (x <= data->width)
		{
			col = ft_col_tohex(data->amb.col) * data->amb.bright;
			ray.direction = ft_ray_direction(data, x, y);
			ray.origin = data->cams->prop.pivot;
			error = ft_cray_fire(data, ray, &col);
			if (error)
				return (error);
//			ft_pixel_put(data, x, y, col);
			x++;
		}
		y++;
	}
	return (0);
//	mlx_pixel_put(data->mlx.data, data->mlx.window, data->width / 2, data->height / 2, 0x00FFFF);
//	mlx_pixel_put(data->mlx.data, data->mlx.window, data->width / 4, data->height / 4, 0x00FFFF);
//	mlx_pixel_put(data->mlx.data, data->mlx.window, data->width / 2, data->height / 4, 0x00FFFF);
//	mlx_pixel_put(data->mlx.data, data->mlx.window, data->width / 4, data->height / 4, 0x00FFFF);
}
