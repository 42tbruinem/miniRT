/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:39:43 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/06 12:42:45 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* t_matrix	*ft_matrix_new(int row, int col)
{
	t_matrix	*new;

	new = malloc(sizeof(t_matrix));
	return (new);
}

t_vec		ft_matrix_mult(t_matrix *a, t_matrix *b)
{
//	matrix is an array of vectors (making up the rows)
//	vector is an array of doubles (making up the columns)
	int index;
	int row;
	int col;
	t_matrix *new;

	row = 0;
	new = ft_matrix_new(ft_length(a[0]), ft_length(b));
	while (a[row])
	{
		col = 0;
		while (b[index][col])
		{
			index = 0;
			while (b[index])
			{
				new[row][col] += a[row][index] * b[index][col];
				index++;
			}
			col++;
		}
		row++;
	}
} */
