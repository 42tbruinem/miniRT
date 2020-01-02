/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_viewport.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/02 12:58:46 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/02 19:14:28 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**first convert to NDC ((x/y + 0.5) / width/height)
**then convert to ScreenSpace
**X: (2 * NDCx) - 1
**Y: (1 - (2 * NDCy))
*/

void	ft_space_convert(t_data *data, int *x, int *y)
{
	int	ratio;

	ratio = data->width / data->height;
	*x = (2 * ((*x + 0.5) / data->width) - 1) * ratio;
	*y = 1 - (2 * ((*y + 0.5) / data->height));
}
