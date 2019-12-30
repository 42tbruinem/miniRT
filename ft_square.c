/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_square.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:09:10 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 19:33:12 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_square_addback(t_square **list, t_square *new)
{
	t_square	*iter;

	iter = *list;
	if (!list)
	{
		*list = new;
		return ;
	}
	while (iter->next)
		iter = iter->next;
	iter->next = new;
}

t_square	*ft_square_new(void)
{
	t_square	*new;

	new = malloc(sizeof(t_square));
	new->color = ft_color_init();
	new->prop = ft_prop_init();
	new->next = NULL;
	new->size = 0;
	return (new);
}

static void	*ft_square_properties(t_square *square)
{
	char	*properties;

	properties = malloc(sizeof(void *) * 8);
	properties[0] = &square->prop.pivot.x;
	properties[1] = &square->prop.pivot.y;
	properties[2] = &square->prop.pivot.z;
	properties[3] = &square->size;
	properties[4] = &square->color.red;
	properties[5] = &square->color.green;
	properties[6] = &square->color.blue;
	properties[7] = 0;
	return ((void *)properties);
}

static int *ft_square_floats(void)
{
	char	*floats;

	floats = malloc(sizeof(int) * (7 + 1));
	if (!floats)
		return (floats);
	floats[0] = 0;
	floats[1] = 1;
	floats[2] = 2;
	floats[3] = 3;
	floats[4] = 4;
	floats[5] = 5;
	floats[6] = 6;
	floats[7] = -1;
	return (floats);
}

void		ft_square_init(char *str, t_data *data)
{
	t_square	*new;
	void		*ppty;
	int			*floats;

	new = ft_square_new();
	ppty = ft_square_properties(new);
	floats = ft_square_floats();
	ft_ato_i_or_f(str, ppty, floats);
	ft_square_addback(&data->sqr, new);
	free(ppty);
}
