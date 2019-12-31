/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_triangle.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:22:30 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/31 15:00:28 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_triangle_addback(t_trngl **list, t_trngl *new)
{
	t_trngl	*iter;

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

t_trngl		*ft_triangle_new(void)
{
	t_trngl	*new;

	new = malloc(sizeof(t_trngl));
	if (!new)
		return (new);
	new->color = ft_color_init();
	new->prop = ft_prop_init();
	new->next = NULL;
	new->p1 = ft_vec_init(0, 0, 0);
	new->p2 = ft_vec_init(0, 0, 0);
	new->p3 = ft_vec_init(0, 0, 0);
	return (new);
}

static void	**ft_triangle_properties(t_trngl *trngl)
{
	void	**properties;

	properties = malloc(sizeof(void *) * 13);
	if (!properties)
		return (properties);
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
	return ((void **)properties);
}

void		ft_triangle_init(char *str, t_data *data, int i)
{
	t_trngl		*new;
	void		**ppty;

	new = ft_triangle_new();
	if (!new)
		return ;
	ppty = ft_triangle_properties(new);
	if (!ppty)
		return ;
	ft_ato_i_or_f(str + i, ppty, 8);
	ft_triangle_addback(&data->tri, new);
	free(ppty);
}
