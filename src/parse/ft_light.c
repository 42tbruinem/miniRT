/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_light.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 17:12:12 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 14:03:13 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_light_clear(t_light **list)
{
	t_light	*iter;
	t_light	*del;

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

void		ft_light_addback(t_light **list, t_light *new)
{
	t_light	*iter;

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

t_light		*ft_light_new(void)
{
	t_light	*new;

	new = malloc(sizeof(t_light));
	new->bright = 0.0;
	new->col = ft_col_init(0, 0, 0);
	new->next = NULL;
	new->prop = ft_prop_init();
	return (new);
}

void		ft_light_properties(void **properties, t_light *light)
{
	properties[0] = &light->prop.pivot.x;
	properties[1] = &light->prop.pivot.y;
	properties[2] = &light->prop.pivot.z;
	properties[3] = &light->bright;
	properties[4] = &light->col.r;
	properties[5] = &light->col.g;
	properties[6] = &light->col.b;
	properties[7] = 0;
}

int			ft_light_init(char *str, t_data *data, int i)
{
	t_light	*new;
	void	*ppty[8];

	new = ft_light_new();
	if (!new)
		return (ERR_MEM);
	ft_light_properties(ppty, new);
	ft_ato_i_or_f(str + i, ppty, 3);
	ft_light_addback(&data->light, new);
	if (ft_isinrange_double(0.0, 1.0, ppty[3], 1) == 0)
		return (ERR_RANGE);
	if (ft_isinrange_int(0, 255, ppty[4], 3) == 0)
		return (ERR_RANGE);
	return (0);
}
