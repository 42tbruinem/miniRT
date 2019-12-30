/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_property.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 16:04:16 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 19:06:52 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_prop	ft_prop_init(void)
{
	t_prop new;

	new.pivot = ft_vec_init(0, 0, 0);
	new.rot = ft_vec_init(0, 0, 0);
	new.trans = ft_vec_init(0, 0, 0);
	new.dir = ft_vec_init(0, 0, 0);
	return (new);
}
