/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_resolution.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 14:49:16 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/07 17:20:47 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
**Void pointer array
**= an array of adresses
**
**to assign to the address, I first need to dereference the array, [j]
**then I need to cast the (void *) to the variable type (int *)
**and then I can dereference that pointer to assign to the actual address
*/

int	ft_resolution_init(char *str, t_data *data, int i)
{
	void	*ppty[3];

	ppty[0] = &data->width;
	ppty[1] = &data->height;
	ft_ato_i_or_f(str + i, ppty, -1);
	if (ft_isinrange_int(0, MAX_WIDTH, ppty[0], 1) == 0)
		*(int *)(ppty[0]) = MAX_WIDTH;
	if (ft_isinrange_int(0, MAX_HEIGHT, ppty[1], 1) == 0)
		*(int *)(ppty[1]) = MAX_HEIGHT;
	return (0);
}
