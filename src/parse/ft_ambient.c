/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ambient.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 15:51:48 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/01 21:36:28 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_ambient_init(char *str, t_data *data, int i)
{
	void	*ppty[5];

	ppty[0] = &data->amb.bright;
	ppty[1] = &data->amb.color.red;
	ppty[2] = &data->amb.color.green;
	ppty[3] = &data->amb.color.blue;
	ft_ato_i_or_f(str + i, ppty, 0);
	return (0);
}
