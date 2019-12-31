/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_square.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:09:10 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/31 15:00:23 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_square_addback(t_square **list, t_square *new)
{
	t_square	*iter;

	iter = *list;
	if (!iter)
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
	if (!new)
		return (new);
	new->color = ft_color_init();
	new->prop = ft_prop_init();
	new->next = NULL;
	new->size = 0;
	return (new);
}

static void	**ft_square_properties(t_square *square)
{
	void	**properties;

	properties = malloc(sizeof(void *) * (10 + 1));
	if (!properties)
		return (properties);
	properties[0] = &square->prop.pivot.x;
	properties[1] = &square->prop.pivot.y;
	properties[2] = &square->prop.pivot.z;
	properties[3] = &square->prop.dir.x;
	properties[4] = &square->prop.dir.y;
	properties[5] = &square->prop.dir.z;
	properties[6] = &square->size;
	properties[7] = &square->color.red;
	properties[8] = &square->color.green;
	properties[9] = &square->color.blue;
	properties[10] = 0;
	return ((void **)properties);
}

void		ft_square_init(char *str, t_data *data, int i)
{
	t_square	*new;
	void		**ppty;

	new = ft_square_new();
	if (!new)
		return ;
	ppty = ft_square_properties(new);
	if (!ppty)
		return ;
	ft_ato_i_or_f(str + i, ppty, 6);
	ft_square_addback(&data->sqr, new);
	free(ppty);
}
