/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:39:43 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/12 13:10:26 by tbruinem      ########   odam.nl         */
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

void	ft_matrix_del(t_matrix mat)
{
	int	i;

	i = 0;
	while (i < mat.row)
	{
		free(mat.mat[i]);
		i++;
	}
	free(mat.mat);
}

t_matrix	ft_matrix_new(int row, int col)
{
	t_matrix	new;
	int			i;
	int			j;

	i = 0;
	new.col = col;
	new.row = row;
	new.mat = malloc(sizeof(double *) * row);
	while (i < row)
	{
		j = 0;
		new.mat[i] = malloc(sizeof(double) * col);
		while (j < col)
		{
			new.mat[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new);
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
	while (row < a.row)
	{
		col = 0;
		while (col < b.col)
		{
			while (index < b.row)
			{
				new.mat[row][col] += a.mat[row][index] * b.mat[index][col];
				index++;
			}
			col++;
			index = 0;
		}
		row++;
	}
	return (new);
}
