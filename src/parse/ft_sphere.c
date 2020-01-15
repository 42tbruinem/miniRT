/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sphere.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 17:21:23 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 14:03:27 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_sphere_clear(t_sphere **list)
{
	t_sphere	*iter;
	t_sphere	*del;

	if (!list)
		return ;
	iter = *list;
	while (iter)
	{
		del = iter;
		iter = iter->next;
		free(del);
	}
}

void		ft_sphere_addback(t_sphere **list, t_sphere *new)
{
	t_sphere	*iter;

	iter = *list;
	if (!iter)
	{
		*list = new;
		return ;
	}
	while (iter->next)
		iter = iter->next;
	iter->next = new;
}

t_sphere	*ft_sphere_new(void)
{
	t_sphere	*new;

	new = malloc(sizeof(t_sphere));
	if (!new)
		return (new);
	new->col = ft_col_init(0, 0, 0);
	new->prop = ft_prop_init();
	new->next = NULL;
	new->diameter = 0;
	return (new);
}

void		ft_sphere_properties(void **properties, t_sphere *sphere)
{
	properties[0] = &sphere->prop.pivot.x;
	properties[1] = &sphere->prop.pivot.y;
	properties[2] = &sphere->prop.pivot.z;
	properties[3] = &sphere->diameter;
	properties[4] = &sphere->col.r;
	properties[5] = &sphere->col.g;
	properties[6] = &sphere->col.b;
	properties[7] = 0;
}

int			ft_sphere_init(char *str, t_data *data, int i)
{
	t_sphere	*new;
	void		*ppty[8];

	new = ft_sphere_new();
	if (!new)
		return (ERR_MEM);
	ft_sphere_properties(ppty, new);
	ft_ato_i_or_f(str + i, ppty, 3);
	ft_sphere_addback(&data->sph, new);
	if (ft_isinrange_int(0, 255, ppty[4], 3) == 0)
		return (ERR_RANGE);
	return (0);
}
