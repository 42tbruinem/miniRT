/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_color.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:00:42 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 18:01:41 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_col	ft_color_init(void)
{
	t_col	new;

	new.red = 0;
	new.green = 0;
	new.blue = 0;
	return (new);
}
