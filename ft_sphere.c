/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sphere.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 17:21:23 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 18:54:24 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_sphere_addback(t_sphere **list, t_sphere *new)
{
	t_sphere	*iter;

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

t_sphere	*ft_sphere_new(void)
{
	t_sphere	*new;

	new = malloc(sizeof(t_sphere));
	new->color = ft_color_init();
	new->prop = ft_prop_init();
	new->next = NULL;
	new->diameter = 0;
	return (new);
}

static void	*ft_sphere_properties(t_sphere *sphere)
{
	char	*properties;

	properties = malloc(sizeof(void *) * 8);
	properties[0] = &sphere->prop.pivot.x;
	properties[1] = &sphere->prop.pivot.y;
	properties[2] = &sphere->prop.pivot.z;
	properties[3] = &sphere->diameter;
	properties[4] = &sphere->color.red;
	properties[5] = &sphere->color.green;
	properties[6] = &sphere->color.blue;
	properties[7] = 0;
	return ((void *)properties);
}

void		ft_sphere_init(char *str, t_data *data)
{
	t_sphere	*new;
	void		*ppty;
	int			i;
	int			j;

	new = ft_sphere_new();
	ppty = ft_sphere_properties(new);
	i = 0;
	j = 0;
	while (str[i] && ((char *)ppty)[j])
	{
		if (str[i] != ' ' && str[i] != ',')
		{
			if (j != 0)
				((int *)ppty)[j] = ft_atoi(str + i, &i);
			else
				((double *)ppty)[j] = ft_atod(str + i, &i);
			j++;
		}
		i++;
	}
	ft_sphere_addback(&data->sph, new);
	free(ppty);
}
