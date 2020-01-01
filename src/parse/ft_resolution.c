/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_resolution.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 14:49:16 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/01 21:40:03 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Void pointer array
= an array of adresses

to assign to the address, I first need to dereference the array, [j]
then I need to cast the (void *) to the variable type (int *)
and then I can dereference that pointer to assign to the actual address
*/

int	ft_resolution_init(char *str, t_data *data, int i)
{
	void	*ppty[3];

	ppty[0] = &data->width;
	ppty[1] = &data->height;
	ft_ato_i_or_f(str + i, ppty, -1);
//	ft_res_print(data);
	return (0);
}
