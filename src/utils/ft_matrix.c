/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:39:43 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/11 16:46:11 by tbruinem      ########   odam.nl         */
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

t_matrix	ft_matrix_new(int row, int col)
{
	t_matrix	new;
	int			i;

	i = 0;
	new.col = col;
	new.row = row;
	new.mat = malloc(sizeof(double *) * row);
	while (i < row)
	{
		new.mat[i] = malloc(sizeof(double) * col);
		i++;
	}
	return (new);
}

void		ft_matrix_init(t_matrix	*mat, double val)
{
	double	**matrix;
	int		i;
	int		j;

	matrix = mat->mat;
	i = 0;
	while (i < mat->row)
	{
		j = 0;
		while (j < mat->col)
		{
			matrix[i][j] = val;
			j++;
		}
		i++;
	}
}

t_matrix	ft_matrix_mult(t_matrix a, t_matrix b)
{
	int			index;
	int			row;
	int			col;
	t_matrix	new;

	row = 0;
	index = 0;
	new = ft_matrix_new(a.row, b.col);
	while (a.mat[row])
	{
		col = 0;
		while (b.mat[index][col])
		{
			index = 0;
			while (b.mat[index])
			{
				new.mat[row][col] += a.mat[row][index] * b.mat[index][col];
				index++;
			}
			col++;
		}
		row++;
	}
	return (new);
}
