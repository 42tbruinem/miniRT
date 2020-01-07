/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_and_return.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 12:11:41 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/07 12:12:19 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_free_and_return(void *mem, int ret)
{
	free(mem);
	return (ret);
}
