/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_color.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:00:42 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/02 14:33:15 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned long	ft_color_tohex(t_col col)
{
	unsigned long r;
	unsigned long g;
	unsigned long b;

	r = (col.red & 0xff) << 16;
	g = (col.green & 0xff) << 8;
	b = (col.blue & 0xff);
	return (r + g + b);
}

t_col			ft_color_torgb(unsigned long hex)
{
	t_col	col;

	col.red = ((hex >> 16) & 0xFF) / 255;
	col.green = ((hex >> 8) & 0xFF) / 255.0;
	col.blue = (hex & 0xFF) / 255.0;
	return (col);
}

t_col			ft_color_init(void)
{
	t_col	new;

	new.red = 0;
	new.green = 0;
	new.blue = 0;
	return (new);
}
