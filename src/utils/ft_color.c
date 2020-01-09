/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_color.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 11:28:07 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/09 11:28:09 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned long	ft_col_tohex(t_col col)
{
	unsigned long r;
	unsigned long g;
	unsigned long b;

	r = (col.r & 0xff) << 16;
	g = (col.g & 0xff) << 8;
	b = (col.b & 0xff);
	return (r + g + b);
}

t_col			ft_col_torgb(unsigned long hex)
{
	t_col	col;

	col.r = ((hex >> 16) & 0xFF) / 255;
	col.g = ((hex >> 8) & 0xFF) / 255.0;
	col.b = (hex & 0xFF) / 255.0;
	return (col);
}

t_col			ft_col_init(void)
{
	t_col	new;

	new.r = 0;
	new.g = 0;
	new.b = 0;
	return (new);
}
