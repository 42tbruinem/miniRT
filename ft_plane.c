/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_plane.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:10:56 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 19:45:49 by tbruinem      ########   odam.nl         */
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

t_plane		*ft_plane_new(void)
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
	if (!properties)
		return (properties);
	properties[0] = &plane->prop.pivot.x;
	properties[1] = &plane->prop.pivot.y;
	properties[2] = &plane->prop.pivot.z;
	properties[3] = &plane->color.red;
	properties[4] = &plane->color.green;
	properties[5] = &plane->color.blue;
	properties[6] = 0;
	return ((void *)properties);
}

static int	*ft_plane_floats(void)
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

void		ft_plane_init(char *str, t_data *data)
{
	t_plane		*new;
	void		*ppty;
	int			*floats;

	new = ft_plane_new();
	ppty = ft_plane_properties(new);
	floats = ft_plane_floats();
	ft_ato_i_or_f(str, ppty, floats);
	ft_plane_addback(&data->pln, new);
	free(ppty);
	free(floats);
}
