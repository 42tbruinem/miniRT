/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_filter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/31 16:57:04 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/31 16:57:04 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_is_valid(char *str)
{
	int i;
	int j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(FILE_TYPE) - 1;
	while (str[i] && j >= 0)
	{
//		printf("STR: %c | VALID: %c\n", str[i], FILE_TYPE[j]);
		if (str[i] != FILE_TYPE[j])
			return (0);
		j--;
		i--;
	}
	return (1);
}
