/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cylinder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:22:45 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 19:45:55 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_cylinder_addback(t_cylndr **list, t_cylndr *new)
{
	t_cylndr	*iter;

	iter = *list;
	if (!list)
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
	new->color = ft_color_init();
	new->width = 0;
	new->height = 0;
	new->prop = ft_prop_init();
	new->next = NULL;
	return (new);
}

static void	*ft_cylinder_properties(t_cylndr *cylndr)
{
	char	*properties;

	properties = malloc(sizeof(void *) * 9);
	if (!properties)
		return (properties);
	properties[0] = &cylndr->prop.pivot.x;
	properties[1] = &cylndr->prop.pivot.y;
	properties[2] = &cylndr->prop.pivot.z;
	properties[3] = &cylndr->width;
	properties[4] = &cylndr->height;
	properties[5] = &cylndr->color.red;
	properties[6] = &cylndr->color.green;
	properties[7] = &cylndr->color.blue;
	properties[8] = 0;
	return ((void *)properties);
}

static int	*ft_cylinder_floats(void)
{
	char	*floats;

	floats = malloc(sizeof(int) * (7 + 1));
	if (!floats)
		return (floats);
	floats[0] = 0;
	floats[1] = 1;
	floats[2] = 2;
	floats[3] = 3;
	floats[4] = 4;
	floats[5] = 5;
	floats[6] = 6;
	floats[7] = -1;
	return (floats);
}

void		ft_cylinder_init(char *str, t_data *data)
{
	t_cylndr	*new;
	void		*ppty;
	int			*floats;

	new = ft_cylinder_new();
	ppty = ft_cylinder_properties(new);
	floats = ft_cylinder_floats();
	ft_ato_i_or_f(str, ppty, floats);
	ft_cylinder_addback(&data->sqr, new);
	free(ppty);
	free(floats);
}
