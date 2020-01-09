/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_struct.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 17:02:04 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/08 21:15:53 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_prop
{
	t_vec		trans;
	t_vec		rot;
	t_vec		pivot;
	t_vec		dir;
}				t_prop;

typedef struct	s_col
{
	int			r;
	int			g;
	int			b;
}				t_col;

typedef struct	s_cam
{
	t_prop			prop;
	int				fov;
	struct s_cam	*next;
}				t_cam;

typedef struct	s_light
{
	t_prop			prop;
	t_col			col;
	double			bright;
	struct s_light	*next;
}				t_light;

typedef struct	s_square
{
	t_prop			prop;
	t_col			col;
	double			size;
	struct s_square	*next;
}				t_square;

typedef struct	s_trngl
{
	t_prop			prop;
	t_col			col;
	t_vec			p1;
	t_vec			p2;
	t_vec			p3;
	struct s_trngl	*next;
}				t_trngl;

typedef struct	s_cylndr
{
	t_prop			prop;
	t_col			col;
	double			width;
	double			height;
	struct s_cylndr	*next;
}				t_cylndr;

typedef struct	s_matrix
{
	double		*col;
}				t_matrix;

typedef struct	s_sphere
{
	t_prop			prop;
	t_col			col;
	double			diameter;
	struct s_sphere	*next;
}				t_sphere;

typedef struct	s_plane
{
	t_prop			prop;
	t_col			col;
	struct s_plane	*next;
}				t_plane;

typedef struct	s_ambient
{
	double		bright;
	t_col		col;
}				t_ambient;

typedef struct	s_mlx
{
	void		*data;
	void		*window;
	void		*image1;
	void		*image2;
	int			bpp;
	int			ll;
	char		*addr1;
	char		*addr2;
	int			endian;
}				t_mlx;

typedef struct	s_colldata
{
	void		*object;
	int			objtype;
	t_vec		hit;
}				t_colldata;

typedef struct	s_ray
{
	t_vec		direction;
	t_vec		origin;
}				t_ray;

typedef struct	s_data
{
	t_cam		*cams;
	t_light		*light;
	t_mlx		mlx;
	int			width;
	int			height;
	t_ambient	amb;
	t_sphere	*sph;
	t_cylndr	*cyl;
	t_square	*sqr;
	t_plane		*pln;
	t_trngl		*tri;
	int			fd;
}				t_data;

#endif
