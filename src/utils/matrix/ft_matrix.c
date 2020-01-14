/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_matrix.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 12:39:43 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/14 19:41:36 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* int		ft_matrix_collen(double *cols)
{
	int i;

	i = 0;
	while (cols + i)
		i++;
	return (i);
} */

/* int		ft_matrix_rowlen(t_matrix rows)
{
	int i;

	i = 0;
	while (rows + i)
		i++;
	return (i);
} */

/* void	ft_matrix_del(t_matrix mat)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
} */

/* t_matrix	ft_matrix_new(int row, int col)
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
} */

void		ft_matrix_print(t_matrix mat)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%8f ", mat[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		ft_matrix_init(t_matrix mat)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
}

void		ft_matrix_dup(t_matrix orig, t_matrix dup)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dup[i][j] = orig[i][j];
			j++;
		}
		i++;
	}
}

void		ft_matrix_mult(t_matrix a, t_matrix b, t_matrix new)
{
	int			index;
	int			row;
	int			col;

	row = 0;
	index = 0;
	ft_matrix_init(new);
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			while (index < 4)
			{
//				printf("new[%d][%d] = %f\n", row, col, new[row][col]);
//				printf("a[%d][%d]   = %f | b[%d][%d] = %f | a * b = %f\n", row, index, a[row][index], index, col, b[index][col], a[row][index] * b[index][col]);
				new[row][col] += a[row][index] * b[index][col];
				index++;
			}
//			printf("\n");
			col++;
			index = 0;
		}
		row++;
	}
}
