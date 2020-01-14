/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_camera.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 16:00:14 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/14 16:05:55 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_camera_cycle(t_data *data)
{
	static int		cam = -1;
	static t_cam	*root;

	if (cam == -1)
	{
		root = data->cams;
		cam++;
	}
	if (cam >= 0)
	{
		data->cams = data->cams->next;
		cam++;
	}
	if (!data->cams)
	{
		data->cams = root;
		cam = 0;
	}
}
