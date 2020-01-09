/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_data.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 17:58:01 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/09 11:17:38 by tbruinem      ########   odam.nl         */
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
	data->mlx.addr1 = NULL;
	data->mlx.addr2 = NULL;
	data->mlx.window = NULL;
	data->mlx.data = NULL;
	data->mlx.image1 = NULL;
	data->mlx.image2 = NULL;
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
		funct = ft_init_funct(ft_identifier_get(line, &i));
		if (funct == NULL)
			return (ERR_ID);
		error = funct(line, data, i);
		if (error)
		{
			free(line);
			return (error);
		}
		free(line);
		if (ret == 0)
			break ;
		ret = get_next_line(fd, &line);
		i = 0;
	}
	return (0);
}

void	ft_data_clear(t_data *data)
{
	if (data == NULL)
		return ;
	ft_camera_clear(&data->cams);
	ft_light_clear(&data->light);
	ft_plane_clear(&data->pln);
	ft_square_clear(&data->sqr);
	ft_sphere_clear(&data->sph);
	ft_triangle_clear(&data->tri);
	ft_cylinder_clear(&data->cyl);
}

int		ft_data_get(t_data *data, int fd)
{
	int		error;

	ft_data_init(data);
	error = ft_data_read(fd, data, 0);
	if (error)
		return (error);
	return (0);
}
