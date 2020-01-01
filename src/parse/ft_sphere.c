/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sphere.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 17:21:23 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/01 21:40:31 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	new->color = ft_color_init();
	new->prop = ft_prop_init();
	new->next = NULL;
	new->diameter = 0;
	return (new);
}

static void	**ft_sphere_properties(t_sphere *sphere)
{
	void	**properties;

	properties = malloc(sizeof(void *) * (7 + 1));
	if (!properties)
		return (properties);
	properties[0] = &sphere->prop.pivot.x;
	properties[1] = &sphere->prop.pivot.y;
	properties[2] = &sphere->prop.pivot.z;
	properties[3] = &sphere->diameter;
	properties[4] = &sphere->color.red;
	properties[5] = &sphere->color.green;
	properties[6] = &sphere->color.blue;
	properties[7] = 0;
	return ((void **)properties);
}

int			ft_sphere_init(char *str, t_data *data, int i)
{
	t_sphere	*new;
	void		**ppty;

	new = ft_sphere_new();
	if (!new)
		return (ERR_MEM);
	ppty = ft_sphere_properties(new);
	if (!ppty)
	{
		free(new);
		return (ERR_MEM);
	}
	ft_ato_i_or_f(str + i, ppty, 3);
	ft_sphere_addback(&data->sph, new);
	free(ppty);
	return (0);
}
