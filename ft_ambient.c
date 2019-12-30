/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ambient.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 15:51:48 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 18:55:52 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_ambient_init(char *str, t_data *data)
{
	void	*ppty[4];
	int		i;
	int		j;

	ppty[0] = &data->amb.bright;
	ppty[1] = &data->amb.color.red;
	ppty[2] = &data->amb.color.green;
	ppty[3] = &data->amb.color.blue;
	i = 0;
	j = 0;
	while (str[i] && ppty[j])
	{
		if (str[i] != ' ' && str[i] != ',')
		{
			if (j != 0)
				*((int *)ppty[j]) = ft_atoi(str + i, &i);
			else
				*((int *)ppty[j]) = ft_atof(str + i, &i);
			j++;
		}
		i++;
	}
}
