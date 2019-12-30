/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digit_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 17:30:34 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 17:43:28 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_power(int pow)
{
	int ret;

	ret = 1;
	while (pow > 0)
	{
		ret = ret * 10;
		pow--;
	}
	return (ret);
}

int		ft_atoi(char *str, int *i)
{
	int n;
	int ret;

	i = 0;
	n = 1;
	ret = 0;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-')
		n = -1;
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ret = ret * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (ret);
}

double	ft_atod(char *str, int *i)
{
	double	ret;
	int		pow;

	pow = 1;
	ret = (double)ft_atoi(str, i);
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			ret = ret + ((str[*i] - '0') / ft_power(pow));
			(*i)++;
			pow++;
		}
	}
	return (ret);
}
