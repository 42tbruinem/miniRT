/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_data.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 17:58:01 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/31 16:15:25 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_data_init(t_data *data)
{
	data->sph = NULL;
	data->cyl = NULL;
	data->pln = NULL;
	data->sqr = NULL;
	data->tri = NULL;
	data->cams = NULL;
	data->light = NULL;
}
