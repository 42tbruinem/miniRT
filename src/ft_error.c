/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 22:24:38 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 22:24:38 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_error(int error)
{
	char *str;

	str = "Error\n";
	write(1, str, ft_strlen(str));
	return (error);
}
