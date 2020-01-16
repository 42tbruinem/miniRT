/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ambient.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 15:51:48 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/16 16:00:54 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_ambient_init(char *str, t_data *data, int i)
{
	void	*ppty[5];

	ppty[0] = &data->amb.bright;
	ppty[1] = &data->amb.col.r;
	ppty[2] = &data->amb.col.g;
	ppty[3] = &data->amb.col.b;
	ppty[4] = 0;
//	printf("I can enter the ambient\n");
	ft_ato_i_or_f(str + i, ppty, 0);
	if (ft_isinrange_double(0.0, 1.0, ppty[0], 1) == 0)
		return (ERR_RANGE);
	if (ft_isinrange_int(0, 255, ppty[1], 3) == 0)
		return (ERR_RANGE);
//	printf("I can exit\n");
	return (0);
}
