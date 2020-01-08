/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:39:43 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/08 15:30:19 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* int		ft_matrix_collen(double *cols)
{
	int i;

	i = 0;
	while (cols[i])
		i++;
	return (i);
}

int		ft_matrix_rowlen(t_matrix *rows)
{
	int i;

	i = 0;
	while (rows[i])
		i++;
	return (i);
}

t_matrix	*ft_matrix_new(int row, int col)
{
	t_matrix	*new;
	int			i;

	i = 0;
	new = malloc(sizeof(t_matrix) * (row + 1));
	while (i < row)
	{
		new[i].col = malloc(sizeof(double *) * (col + 1));
		i++;
	}
	new[i] = 0;
	new[i - 1].col[i - 1] = 0;
	return (new);
}

t_matrix	*ft_matrix_c_to_w()
{
	t_matrix	*matrix;

	matrix = ft_matrix_new(4, 4);
	matrix[0].val = 0;
	matrix[1].val = 0;
	matrix[2].val = 0;
	matrix[3].val = 0;
	matrix[0].col[0] = 0;
	matrix[0].col[1] = 0;
	matrix[0].col[2] = 0;
	matrix[0].col[3] = 0;
	matrix[1].col[0] = 0;
	matrix[1].col[1] = 0;
	matrix[1].col[2] = 0;
	matrix[1].col[3] = 0;
	matrix[2].col[0] = 0;
	matrix[2].col[1] = 0;
	matrix[2].col[2] = 0;
	matrix[2].col[3] = 0;
	matrix[3].col[0] = 0;
	matrix[3].col[1] = 0;
	matrix[3].col[2] = 0;
	matrix[3].col[3] = 1;
	return (matrix);
}

t_vec		ft_matrix_mult(t_matrix *a, t_matrix *b)
{
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
}
 */