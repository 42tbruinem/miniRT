/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_resolution.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 14:49:16 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 18:00:08 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_resolution_init(char *str, t_data *data)
{
	void	*ppty[3];
	int		i;
	int		j;

	ppty[0] = &data->width;
	ppty[1] = &data->height;
	i = 0;
	j = 0;
	while (str[i] && ppty[j])
	{
		if (str[i] != ' ' && str[i] != ',')
		{
			*((int *)ppty[j]) = ft_atoi(str + i, &i);
			j++;
		}
		i++;
	}
}
