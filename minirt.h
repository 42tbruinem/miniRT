/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 10:44:24 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 19:32:39 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# define RES_ID "R"
# define AMB_ID "A"
# define CAM_ID "c"
# define LIGHT_ID "l"
# define SPH_ID "sp"
# define PLN_ID "pl"
# define SQR_ID "sq"
# define CYL_ID "cy"
# define TRI_ID "tr"

enum	e_identifiers
{
	ERROR = -1,
	RES,
	AMB,
	CAM,
	LIGHT,
	SPH,
	PLN,
	SQR,
	CYL,
	TRI,
};

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
	int			red;
	int			green;
	int			blue;
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
	t_col			color;
	double			bright;
	struct s_light	*next;
}				t_light;

typedef struct	s_square
{
	t_prop			prop;
	t_col			color;
	double			size;
	struct s_square	*next;
}				t_square;

typedef struct	s_trngl
{
	t_prop			prop;
	t_col			color;
	t_vec			p1;
	t_vec			p2;
	t_vec			p3;
	struct s_trngl	*next;
}				t_trngl;

typedef struct	s_cylndr
{
	t_prop			prop;
	t_col			color;
	double			width;
	double			height;
	struct s_cylndr	*next;
}				t_cylndr;

typedef struct	s_sphere
{
	t_prop			prop;
	t_col			color;
	double			diameter;
	struct s_sphere	*next;
}				t_sphere;

typedef struct	s_plane
{
	t_prop			prop;
	t_col			color;
	struct s_plane	*next;
}				t_plane;

typedef struct	s_ambient
{
	double		bright;
	t_col		color;
}				t_ambient;

typedef struct	s_data
{
	t_cam		*cams;
	t_light		*light;
	char		***scene;
	int			width;
	int			height;
	t_ambient	amb;
	t_sphere	*sph;
	t_cylndr	*cyl;
	t_square	*sqr;
	t_plane		*pln;
	t_trngl		*tri;
}				t_data;

int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str, int *i);
double			ft_atod(char *str, int *i);

void			ft_ato_i_or_f(char *str, void *ppty, int *floats);

typedef void	(*t_initf)(t_data *data);
t_initf			ft_jumptable(int id);

t_col			ft_color_init(void);
t_prop			ft_prop_init(void);
t_vec			ft_vec_init(int x, int y, int z);

void			ft_data_init(t_data *data);
void			ft_camera_init(char *str, t_data *data);
void			ft_resolution_init(char *str, t_data *data);
void			ft_ambient_init(char *str, t_data *data);
void			ft_light_init(char *str, t_data *data);
void			ft_sphere_init(char *str, t_data *data);
void			ft_cylinder_init(char *str, t_data *data);
void			ft_plane_init(char *str, t_data *data);
void			ft_square_init(char *str, t_data *data);
void			ft_triangle_init(char *str, t_data *data);

t_data			ft_scene_read(int file);

#endif
