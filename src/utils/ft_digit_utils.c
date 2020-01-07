/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digit_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 17:30:34 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/07 17:19:19 by tbruinem      ########   odam.nl         */
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

	n = 1;
	ret = 0;
	while ((str[*i] >= 9 && str[*i] <= 13)
			|| (str[*i] == ' ' || str[*i] == ','))
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
	return (ret * n);
}

double	ft_atod(char *str, int *i)
{
	double	ret;
	int		pow;
	double	tmp;
	double	n;

	pow = 1;
	ret = (double)ft_atoi(str, i);
	n = (ret < 0) ? -1.0 : 1.0;
	ret *= n;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			tmp = (double)(str[*i] - '0') / ft_power(pow);
			ret = ret + tmp;
			(*i)++;
			pow++;
		}
	}
	return (ret * n);
}

void	ft_ato_i_or_f(char *str, void **ppty, int floats)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] && (char *)(ppty[j]))
	{
		if (str[i] != ' ' && str[i] != ',')
		{
			if (j <= floats)
				*(double *)(ppty[j]) = ft_atod(str, &i);
			else
				*(int *)(ppty[j]) = ft_atoi(str, &i);
			j++;
		}
		i++;
	}
}
