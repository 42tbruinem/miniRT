/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_camera.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 15:59:30 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/31 15:33:31 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_camera_addback(t_cam **list, t_cam *new)
{
	t_cam	*iter;

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

t_cam		*ft_camera_new(void)
{
	t_cam	*new;

	new = malloc(sizeof(t_cam));
	if (new == NULL)
		return (new);
	new->fov = 0;
	new->next = NULL;
	new->prop = ft_prop_init();
	return (new);
}

static void	**ft_camera_properties(t_cam *cam)
{
	void	**properties;

	properties = malloc(sizeof(void *) * 8);
	if (properties == NULL)
		return (NULL);
	properties[0] = &cam->prop.pivot.x;
	properties[1] = &cam->prop.pivot.y;
	properties[2] = &cam->prop.pivot.z;
	properties[3] = &cam->prop.dir.x;
	properties[4] = &cam->prop.dir.y;
	properties[5] = &cam->prop.dir.z;
	properties[6] = &cam->fov;
	properties[7] = 0;
	return ((void **)properties);
}

void		ft_camera_init(char *str, t_data *data, int i)
{
	t_cam	*new;
	void	**ppty;
	int		j;

	new = ft_camera_new();
	if (!new)
		return ;
	ppty = ft_camera_properties(new);
	if (!ppty)
		return ;
	j = 0;
	while (str[i] && (char *)(ppty[j]))
	{
		if (str[i] != ' ' && str[i] != ',')
		{
			if (j <= 5)
				*(double *)(ppty[j]) = ft_atod(str, &i);
			else
				*(int *)(ppty[j]) = ft_atoi(str, &i);
			j++;
		}
		i++;
	}
	ft_camera_addback(&data->cams, new);
	free(ppty);
}
