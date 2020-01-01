/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_data.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 17:58:01 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/01 21:34:31 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_data_init(t_data *data)
{
	data->sph = NULL;
	data->cyl = NULL;
	data->pln = NULL;
	data->sqr = NULL;
	data->tri = NULL;
	data->cams = NULL;
	data->light = NULL;
}

int		ft_data_read(int fd, t_data *data, int i)
{
	int		ret;
	int		error;
	char	*line;
	t_initf	funct;

	ret = get_next_line(fd, &line);
	while (ret != -1)
	{
		funct = ft_jumptable(ft_identifier_get(line, &i));
		if (funct != NULL)
		{
			error = funct(line, data, i);
			if (error)
			{
				free(line);
				return (error);
			}
		}
		free(line);
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
		i = 0;
	}
}

int		ft_data_get(t_data *data, int fd)
{
	char	*line;
	int		ret;
	int		error;

	ft_data_init(data);
	error = ft_data_read(fd, data, 0);
	if (error)
		return (error);
	return (0);
}
