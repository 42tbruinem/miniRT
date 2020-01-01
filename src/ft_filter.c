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

int		ft_isinrange_double(double min, double max, void *property, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (((double *)property)[i] >= min && ((double *)property)[i] <= max)
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_isinrange_int(int min, int max, void *property, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (((int *)property)[i] >= min && ((int *)property)[i] <= max)
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_is_valid(char *str)
{
	int i;
	int j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(FILE_TYPE) - 1;
	while (str[i] && j >= 0)
	{
		if (str[i] != FILE_TYPE[j])
			return (0);
		j--;
		i--;
	}
	return (1);
}

int		ft_filter_input(int argc, char **input)
{
	int fd;

	if (argc < 2 || argc > 2)
		return (ERR_ARG);
	fd = open(input[1], O_RDONLY);
	if (ft_is_valid(input[1]) == 0)
		return (ERR_TYPE);
	if (read(fd, (void *)0, 0) == -1)
		return (ERR_FILE);
	return (0);
}
