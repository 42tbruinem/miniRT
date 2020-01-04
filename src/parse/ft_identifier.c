/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_identifier.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 13:27:35 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/04 16:47:15 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_identifier_parse(char *id)
{
	if (ft_strcmp(id, RES_ID) == 0)
		return (I_RES);
	else if (ft_strcmp(id, AMB_ID) == 0)
		return (I_AMB);
	else if (ft_strcmp(id, CAM_ID) == 0)
		return (I_CAM);
	else if (ft_strcmp(id, LIGHT_ID) == 0)
		return (I_LIGHT);
	else if (ft_strcmp(id, SPH_ID) == 0)
		return (I_SPH);
	else if (ft_strcmp(id, PLN_ID) == 0)
		return (I_PLN);
	else if (ft_strcmp(id, SQR_ID) == 0)
		return (I_SQR);
	else if (ft_strcmp(id, CYL_ID) == 0)
		return (I_CYL);
	else if (ft_strcmp(id, TRI_ID) == 0)
		return (I_TRI);
	else
		return (I_ERROR);
}

int		ft_identifier_get(char *str, int *i)
{
	char	*id;
	int		ret;

	id = malloc(sizeof(char) * 3);
	while (str[*i] && *i < 2)
	{
		if (str[*i] == ' ')
			break ;
		else
			id[*i] = str[*i];
		(*i)++;
	}
	id[*i] = 0;
	ret = ft_identifier_parse(id);
	free(id);
	return (ret);
}
