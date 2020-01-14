/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_filter.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/31 16:57:04 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/14 16:14:56 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_isnormalized(t_vec orientation)
{
	double	x;
	double	y;
	double	z;
	double	res;

	x = orientation.x;
	y = orientation.y;
	z = orientation.z;
	res = (x * x) + (y * y) + (z * z);
	if (res >= 0.999 && res <= 1.001)
		return (1);
	return (0);
}

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

int		ft_filter_input(t_data *data, int argc, char **input)
{
	int fd;

	if (argc < 2)
		return (ERR_ARG);
	if (argc > 3)
	{
		if (ft_strcmp(input[2], "--save") == 1)
			return (ERR_ARG);
		else
		{
			data->save = 1;
			data->fd = open("bmpsave.bmp", O_WRONLY | O_CREAT, 0644);
		}
	}
	fd = open(input[1], O_RDONLY);
	if (read(fd, (void *)0, 0) == -1)
		return (ERR_FILE);
	if (ft_is_valid(input[1]) == 0)
		return (ERR_TYPE);
	return (0);
}
