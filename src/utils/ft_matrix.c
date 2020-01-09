/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:39:43 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/08 20:52:20 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_matrix_collen(double *cols)
{
	int i;

	i = 0;
	while (cols + i)
		i++;
	return (i);
}

int		ft_matrix_rowlen(double **rows)
{
	int i;

	i = 0;
	while (rows + i)
		i++;
	return (i);
}

double	**ft_matrix_new(int row, int col)
{
	double		**new;
	int			i;

	i = 0;
	new = malloc(sizeof(double *) * (row + 1));
	while (i < row)
	{
		new[i] = malloc(sizeof(double) * (col + 1));
		new[i][col] = 0;
		i++;
	}
	new[i] = 0;
	new[row][col] = 0;
	return (new);
}

double	**ft_matrix_c_to_w()
{
	double	**matrix;

	matrix = ft_matrix_new(4, 4);
	matrix[0][0] = 0;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[0][3] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = 0;
	matrix[1][2] = 0;
	matrix[1][3] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 0;
	matrix[2][3] = 0;
	matrix[3][0] = 0;
	matrix[3][1] = 0;
	matrix[3][2] = 0;
	matrix[3][3] = 1;
	return (matrix);
}

double	**ft_matrix_mult(double **a, double **b)
{
	int			index;
	int			row;
	int			col;
	double		**new;

	row = 0;
	new = ft_matrix_new(ft_matrix_rowlen(a), ft_matrix_collen(b[0]));
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
	return (new);
}
