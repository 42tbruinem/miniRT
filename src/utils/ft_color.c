/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_color.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 11:28:07 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 14:07:30 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_col			ft_col_mult(t_col col, t_col add, double bright)
{
	col.r += col.r * (add.r * bright);
	col.g += col.g * (add.g * bright);
	col.b += col.b * (add.b * bright);
	return (col);
}

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

	col.r = (hex >> 16) & 0x0000FF;
	col.g = (hex >> 8) & 0x0000FF;
	col.b = hex & 0x0000FF;
	return (col);
}

t_col			ft_col_init(int r, int g, int b)
{
	t_col	new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}
