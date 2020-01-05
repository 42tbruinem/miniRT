/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 10:44:24 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/05 01:04:10 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# define FILE_TYPE ".rt"

# define RES_ID "R"
# define AMB_ID "A"
# define CAM_ID "c"
# define LIGHT_ID "l"
# define SPH_ID "sp"
# define PLN_ID "pl"
# define SQR_ID "sq"
# define CYL_ID "cy"
# define TRI_ID "tr"

# ifndef MAX_WIDTH
#  define MAX_WIDTH 2560
# endif
# ifndef MAX_HEIGHT
#  define MAX_HEIGHT 1440
# endif

enum	e_errors
{
	ERR_ARG = 1,
	ERR_TYPE,
	ERR_FILE,
	ERR_NORMAL,
	ERR_MEM,
	ERR_RANGE,
	ERR_ID,
};

enum	e_collision
{
	C_SPH,
	C_PLN,
	C_SQR,
	C_CYL,
	C_TRI,
};

enum	e_initialize
{
	I_ERROR = -1,
	I_RES,
	I_AMB,
	I_CAM,
	I_LIGHT,
	I_SPH,
	I_PLN,
	I_SQR,
	I_CYL,
	I_TRI,
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
	void		*image;
}				t_mlx;

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
}				t_data;

int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str, int *i);
double			ft_atod(char *str, int *i);
void			ft_ato_i_or_f(char *str, void **ppty, int floats);

t_vec			ft_ray_direction(t_data *data, int x, int y);
int				ft_render(t_data *data);

int				ft_error(int error);
int				ft_is_valid(char *str);
int				ft_filter_input(int argc, char **input);
int				ft_isinrange_int(int min, int max, void *property, int size);
int				ft_isinrange_double(double min, double max,
				void *property, int size);

typedef	void	(*t_collf)(t_ray ray, void *obj, unsigned int *col, t_vec *hit);
t_collf			ft_coll_funct(int id);

typedef int		(*t_initf)(char *str, t_data *data, int i);
t_initf			ft_init_funct(int id);

unsigned long	ft_col_tohex(t_col col);
t_col			ft_col_torgb(unsigned long hex);
t_col			ft_col_init(void);
t_prop			ft_prop_init(void);

void 			ft_cray_sphere(t_ray ray, void *obj, unsigned int *col, t_vec *hit);

t_vec			ft_vec_sub(t_vec a, t_vec b);
t_vec			ft_vec_add(t_vec a, t_vec b);
t_vec			ft_vec_scale(t_vec vector, double scalar);
t_vec			ft_vec_init(int x, int y, int z);
t_vec			ft_normalize(t_vec vector);
double			ft_vec_length(t_vec a, t_vec b);
double			ft_dotp(t_vec a, t_vec b);

void			ft_camera_clear(t_cam **list);
void			ft_light_clear(t_light **list);
void			ft_sphere_clear(t_sphere **list);
void			ft_cylinder_clear(t_cylndr **list);
void			ft_plane_clear(t_plane **list);
void			ft_square_clear(t_square **list);
void			ft_triangle_clear(t_trngl **list);

int				ft_camera_init(char *str, t_data *data, int i);
int				ft_resolution_init(char *str, t_data *data, int i);
int				ft_ambient_init(char *str, t_data *data, int i);
int				ft_light_init(char *str, t_data *data, int i);
int				ft_sphere_init(char *str, t_data *data, int i);
int				ft_cylinder_init(char *str, t_data *data, int i);
int				ft_plane_init(char *str, t_data *data, int i);
int				ft_square_init(char *str, t_data *data, int i);
int				ft_triangle_init(char *str, t_data *data, int i);

int				ft_identifier_get(char *str, int *i);
int				ft_identifier_parse(char *id);

void			ft_data_init(t_data *data);
int				ft_data_get(t_data *data, int fd);
int				ft_data_read(int fd, t_data *data, int i);

void			ft_data_print(t_data *data);

#endif
