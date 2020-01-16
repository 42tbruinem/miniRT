/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ray_light.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 00:06:34 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/16 00:23:25 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_lray_sphere(t_sphere *sphere, t_raydata *rdata)
{


}

int		ft_lightray(t_data *data, t_raydata *rdata)
{
	t_light		*root;
	int			ret;
	int			obj;
	t_loopf		funct;

	obj = SPH;
	root = data->light;
	ret = 0;
	while (data->light)
	{
		rdata->dist = ft_vec_length(rdata->hit, data->light->prop.pivot);
		funct = ft_loop_funct(obj);
		if (funct(data, rdata, LIGHT_RAY) == 0)

		data->light = data->light->next;
	}
	data->light = root;
	return (ret);
}
