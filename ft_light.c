/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_light.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 17:12:12 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 17:52:18 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_light_addback(t_light **list, t_light *new)
{
	t_light	*iter;

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

t_light		*ft_light_new(void)
{
	t_light	*new;

	new = malloc(sizeof(t_light));
	new->bright = 0.0;
	new->color.red = 0;
	new->color.green = 0;
	new->color.blue = 0;
	new->next = NULL;
	new->prop = ft_prop_init();
	return (new);
}

static void	*ft_light_properties(t_light *light)
{
	char	*properties;

	properties = malloc(sizeof(void *) * 8);
	properties[0] = &light->prop.pivot.x;
	properties[1] = &light->prop.pivot.y;
	properties[2] = &light->prop.pivot.z;
	properties[3] = &light->bright;
	properties[4] = &light->color.red;
	properties[5] = &light->color.green;
	properties[6] = &light->color.blue;
	properties[7] = 0;
	return ((void *)properties);
}

void		ft_light_init(char *str, t_data *data)
{
	t_light	*new;
	void	*ppty;
	int		i;
	int		j;

	new = ft_light_new();
	ppty = ft_light_properties(new);
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
	ft_light_addback(&data->light, new);
	free(ppty);
}
