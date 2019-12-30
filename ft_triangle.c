/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_triangle.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:22:30 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 18:54:11 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_triangle_addback(t_trngl **list, t_trngl *new)
{
	t_trngl	*iter;

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

t_trngl		*ft_triangle_new(void)
{
	t_trngl	*new;

	new = malloc(sizeof(t_trngl));
	new->color = ft_color_init();
	new->prop = ft_prop_init();
	new->next = NULL;
	new->p1 = ft_vec_init(0, 0, 0);
	new->p2 = ft_vec_init(0, 0, 0);
	new->p3 = ft_vec_init(0, 0, 0);
	return (new);
}

static void	*ft_triangle_properties(t_trngl *trngl)
{
	char	*properties;

	properties = malloc(sizeof(void *) * 13);
	properties[0] = &trngl->p1.x;
	properties[1] = &trngl->p1.y;
	properties[2] = &trngl->p1.z;
	properties[3] = &trngl->p2.x;
	properties[4] = &trngl->p2.y;
	properties[5] = &trngl->p2.z;
	properties[6] = &trngl->p3.x;
	properties[7] = &trngl->p3.y;
	properties[8] = &trngl->p3.z;
	properties[9] = &trngl->color.red;
	properties[10] = &trngl->color.green;
	properties[11] = &trngl->color.blue;
	properties[12] = 0;
	return ((void *)properties);
}

void		ft_triangle_init(char *str, t_data *data)
{
	t_trngl		*new;
	void		*ppty;
	int			i;
	int			j;

	new = ft_triangle_new();
	ppty = ft_triangle_properties(new);
	i = 0;
	j = 0;
	while (str[i] && ((char *)ppty)[j])
	{
		if (str[i] != ' ' && str[i] != ',')
		{
			if (j != 0)
				((int *)ppty)[j] = ft_atoi(str + i, &i);
			else
				((double *)ppty)[j] = ft_atod(str + i, &i);
			j++;
		}
		i++;
	}
	ft_triangle_addback(&data->tri, new);
	free(ppty);
}
