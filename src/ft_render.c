/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_render.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 12:57:02 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/05 17:26:43 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* void			ft_pixel_put(t_data *data, int x, int y, unsigned int col)
{
	mlx_pixel_put(data->mlx.data, data->mlx.window, x, y, col);
} */

//this fills our object list.

void	ft_objects_get(void **objects, t_data *data)
{
	objects[C_SPH] = data->sph;
	objects[C_PLN] = data->pln;
	objects[C_SQR] = data->sqr;
	objects[C_CYL] = data->cyl;
	objects[C_TRI] = data->tri;
	objects[5] = 0;
}

//this increases the list pointer of our object

void	*ft_object_iter(void *obj, int i)
{
	if (i == C_SPH)
		return (((t_sphere *)obj)->next);
	if (i == C_PLN)
		return (((t_plane *)obj)->next);
	if (i == C_SQR)
		return (((t_square *)obj)->next);
	if (i == C_CYL)
		return (((t_cylndr *)obj)->next);
	if (i == C_TRI)
		return (((t_trngl *)obj)->next);
	return (NULL);
}	

//this checks every object for collision with the ray.

void	ft_ray_coll(t_data *data, t_ray ray, unsigned int *col)
{
	int		i;
	t_vec	hit;
	t_collf	funct;
	void	*objects[6];

	i = 0;
	hit = ray.origin;
	ft_objects_get(objects, data);
//	printf("objects gotten\n");
	while (objects[i])
	{
		funct = ft_coll_funct(i);
//		printf("funct acquired | pointer: %p\n", funct);
		while (objects[i])
		{
			if (!funct)
				return ;
			funct(ray, objects[i], col, &hit);
			objects[i] = ft_object_iter(objects[i], i);
//			printf("i : %d | col: %x\n", i, *col);
		}
		i++;
	}
//	return (ret);
}

//this fires the rays at every X and Y coordinate.

int		ft_render(t_data *data)
{
	int				x;
	int				y;
	unsigned int	col;
	t_col			color;
	t_ray			ray;

	y = 0;
	col = 0;
	printf("P6\n%d %d\n255\n", data->width, data->height);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			col = ft_col_tohex(data->amb.col) * data->amb.bright;
			ray.direction = ft_ray_direction(data, x, y);
			ray.origin = data->cams->prop.pivot;
			ft_ray_coll(data, ray, &col);
			color = ft_col_torgb(col);
			printf("%c%c%c", color.r, color.g, color.b);
//			ft_pixel_put(data, x, y, col);
			x++;
		}
		y++;
	}
	return (0);
}
