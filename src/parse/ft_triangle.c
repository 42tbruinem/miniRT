/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_triangle.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 18:22:30 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 14:03:38 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_triangle_clear(t_trngl **list)
{
	t_trngl	*iter;
	t_trngl	*del;

	if (!list)
		return ;
	iter = *list;
	while (iter)
	{
		del = iter;
		iter = iter->next;
		free(del);
	}
}

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
	new->col = ft_col_init(0, 0, 0);
	new->prop = ft_prop_init();
	new->next = NULL;
	new->p1 = ft_vec_init(0, 0, 0);
	new->p2 = ft_vec_init(0, 0, 0);
	new->p3 = ft_vec_init(0, 0, 0);
	return (new);
}

void		ft_triangle_properties(void **properties, t_trngl *trngl)
{
	properties[0] = &trngl->p1.x;
	properties[1] = &trngl->p1.y;
	properties[2] = &trngl->p1.z;
	properties[3] = &trngl->p2.x;
	properties[4] = &trngl->p2.y;
	properties[5] = &trngl->p2.z;
	properties[6] = &trngl->p3.x;
	properties[7] = &trngl->p3.y;
	properties[8] = &trngl->p3.z;
	properties[9] = &trngl->col.r;
	properties[10] = &trngl->col.g;
	properties[11] = &trngl->col.b;
	properties[12] = 0;
}

int			ft_triangle_init(char *str, t_data *data, int i)
{
	t_trngl		*new;
	void		*ppty[13];

	new = ft_triangle_new();
	if (!new)
		return (ERR_MEM);
	ft_triangle_properties(ppty, new);
	ft_ato_i_or_f(str + i, ppty, 8);
	ft_triangle_addback(&data->tri, new);
	if (ft_isinrange_int(0, 255, ppty[9], 3) == 0)
		return (ERR_RANGE);
	return (0);
}
