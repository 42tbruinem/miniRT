/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cylinder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:22:45 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 14:02:40 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_cylinder_clear(t_cylndr **list)
{
	t_cylndr	*iter;
	t_cylndr	*del;

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

void		ft_cylinder_addback(t_cylndr **list, t_cylndr *new)
{
	t_cylndr	*iter;

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

t_cylndr	*ft_cylinder_new(void)
{
	t_cylndr	*new;

	new = malloc(sizeof(t_cylndr));
	if (!new)
		return (new);
	new->col = ft_col_init(0, 0, 0);
	new->width = 0;
	new->height = 0;
	new->prop = ft_prop_init();
	new->next = NULL;
	return (new);
}

void		ft_cylinder_properties(void **properties, t_cylndr *cylndr)
{
	properties[0] = &cylndr->prop.pivot.x;
	properties[1] = &cylndr->prop.pivot.y;
	properties[2] = &cylndr->prop.pivot.z;
	properties[3] = &cylndr->prop.dir.x;
	properties[4] = &cylndr->prop.dir.y;
	properties[5] = &cylndr->prop.dir.z;
	properties[6] = &cylndr->width;
	properties[7] = &cylndr->height;
	properties[8] = &cylndr->col.r;
	properties[9] = &cylndr->col.g;
	properties[10] = &cylndr->col.b;
	properties[11] = 0;
}

int			ft_cylinder_init(char *str, t_data *data, int i)
{
	t_cylndr	*new;
	void		*ppty[12];

	new = ft_cylinder_new();
	if (!new)
		return (ERR_MEM);
	ft_cylinder_properties(ppty, new);
	ft_ato_i_or_f(str + i, ppty, 7);
	ft_cylinder_addback(&data->cyl, new);
	if (ft_isinrange_double(-1.0, 1.0, ppty[3], 3) == 0)
		return (ERR_RANGE);
	if (ft_isinrange_int(0, 255, ppty[8], 3) == 0)
		return (ERR_RANGE);
	if (!ft_isnormalized(new->prop.dir))
		return (ERR_NORMAL);
	return (0);
}
