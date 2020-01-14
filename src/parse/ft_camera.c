/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_camera.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 15:59:30 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/14 21:50:52 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_camera_clear(t_cam **list)
{
	t_cam	*iter;
	t_cam	*del;

	if (!list)
		return ;
	iter = *list;
	while (iter)
	{
		del = iter;
		iter = iter->next;
		free(del);
		del = NULL;
	}
}

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

static void	ft_camera_properties(void **properties, t_cam *cam)
{
	properties[0] = &cam->prop.pivot.x;
	properties[1] = &cam->prop.pivot.y;
	properties[2] = &cam->prop.pivot.z;
	properties[3] = &cam->prop.dir.x;
	properties[4] = &cam->prop.dir.y;
	properties[5] = &cam->prop.dir.z;
	properties[6] = &cam->fov;
	properties[7] = 0;
}

int			ft_camera_init(char *str, t_data *data, int i)
{
	t_cam	*new;
	void	*ppty[10];

//	printf("I can start initializing a camera\n");
	new = ft_camera_new();
	if (!new)
		return (ERR_MEM);
	ft_camera_properties(ppty, new);
	ft_ato_i_or_f(str + i, ppty, 5);
	ft_camera_addback(&data->cams, new);
	if (ft_isinrange_double(-1.0, 1.0, ppty[3], 3) == 0)
		return (ERR_RANGE);
	if (ft_isinrange_int(0, 180, ppty[6], 1) == 0)
		return (ERR_RANGE);
	if (!ft_isnormalized(new->prop.dir))
		return (ERR_NORMAL);
	ft_matrix_init(new->c2w);
	ft_lookat(new);
	ft_matrix_print(new->c2w);
//	ft_c2w_update(new);
//	printf("I can exit\n");
	return (0);
}
