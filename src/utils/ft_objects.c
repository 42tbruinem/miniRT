/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_objects.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 13:38:28 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/06 17:09:00 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_object_get(void **objects, t_data *data)
{
	objects[SPH] = data->sph;
	objects[PLN] = data->pln;
	objects[SQR] = data->sqr;
	objects[CYL] = data->cyl;
	objects[TRI] = data->tri;
	objects[5] = 0;
}

void	*ft_object_iter(void *obj, int type)
{
	if (type == SPH)
		return (((t_sphere *)obj)->next);
	if (type == PLN)
		return (((t_plane *)obj)->next);
	if (type == SQR)
		return (((t_square *)obj)->next);
	if (type == CYL)
		return (((t_cylndr *)obj)->next);
	if (type == TRI)
		return (((t_trngl *)obj)->next);
	return (NULL);
}
