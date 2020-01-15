/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_identifier.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 13:27:35 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/15 14:39:05 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_identifier_parse(char *id)
{
	if (ft_strcmp(id, RES_ID) == 0)
		return (RES);
	else if (ft_strcmp(id, AMB_ID) == 0)
		return (AMB);
	else if (ft_strcmp(id, CAM_ID) == 0)
		return (CAM);
	else if (ft_strcmp(id, LIGHT_ID) == 0)
		return (LIGHT);
	else if (ft_strcmp(id, SPH_ID) == 0)
		return (SPH);
	else if (ft_strcmp(id, PLN_ID) == 0)
		return (PLN);
	else if (ft_strcmp(id, SQR_ID) == 0)
		return (SQR);
	else if (ft_strcmp(id, CYL_ID) == 0)
		return (CYL);
	else if (ft_strcmp(id, TRI_ID) == 0)
		return (TRI);
	else
		return (ERROR);
}

int		ft_identifier_get(char *str, int *i)
{
	char	id[3];
	int		ret;

	while (str[*i] && *i < 2)
	{
		if (str[*i] == ' ')
			break ;
		else
			id[*i] = str[*i];
		(*i)++;
	}
	ret = ft_identifier_parse(id);
	return (ret);
}
