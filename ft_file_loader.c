/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file_loader.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 19:19:08 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 19:30:49 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_arrint(int *array, int n)
{
	int i;

	i = 0;
	while (array[i] != -1)
	{
		if (array[i] == n)
			return (1);
		i++;
	}
	return (0);
}

void	ft_ato_i_or_f(char *str, void *ppty, int *floats)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && ((char *)ppty)[j])
	{
		if (str[i] != ' ' && str[i] != ',')
		{
			if (ft_arrint(floats, j))
				((double *)ppty)[j] = ft_atod(str + i, &i);
			else
				((int *)ppty)[j] = ft_atoi(str + i, &i);
			j++;
		}
		i++;
	}
}
