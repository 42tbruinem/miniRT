/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_plane.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:10:56 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 18:54:33 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_plane_addback(t_plane **list, t_plane *new)
{
	t_plane	*iter;

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

t_plane	*ft_plane_new(void)
{
	t_plane	*new;

	new = malloc(sizeof(t_plane));
	new->color = ft_color_init();
	new->prop = ft_prop_init();
	new->next = NULL;
	return (new);
}

static void	*ft_plane_properties(t_plane *plane)
{
	char	*properties;

	properties = malloc(sizeof(void *) * 8);
	properties[0] = &plane->prop.pivot.x;
	properties[1] = &plane->prop.pivot.y;
	properties[2] = &plane->prop.pivot.z;
	properties[3] = &plane->color.red;
	properties[4] = &plane->color.green;
	properties[5] = &plane->color.blue;
	properties[6] = 0;
	return ((void *)properties);
}

void		ft_plane_init(char *str, t_data *data)
{
	t_plane		*new;
	void		*ppty;
	int			i;
	int			j;

	new = ft_plane_new();
	ppty = ft_plane_properties(new);
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
	ft_plane_addback(&data->pln, new);
	free(ppty);
}
