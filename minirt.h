/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 10:44:24 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/11 17:29:22 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "minirt_enum.h"
# include "minirt_struct.h"

# include <mlx.h>
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

int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str, int *i);
double			ft_atod(char *str, int *i);
void			ft_ato_i_or_f(char *str, void **ppty, int floats);

void			ft_object_get(void **objects, t_data *data);
void			*ft_object_iter(void *obj, int type);
/*
**Ray functions
*/
void			ft_ray_coll(t_data *data, t_ray ray, unsigned int *col);
t_ray			ft_ray_init(t_data *data, int x, int y);

int				ft_matrix_collen(double *cols);
int				ft_matrix_rowlen(double **rows);
t_matrix		ft_matrix_new(int row, int col);
t_matrix		ft_matrix_mult(t_matrix a, t_matrix b);
void			ft_matrix_init(t_matrix *mat, double val);


/*
**Input filtering
*/
int				ft_error(t_data *data, int error);
int				ft_is_valid(char *str);
int				ft_filter_input(t_data *data, int argc, char **input);
int				ft_isinrange_int(int min, int max, void *property, int size);
int				ft_isinrange_double(double min, double max,
				void *property, int size);
int				ft_isnormalized(t_vec orientation);

/*
**Jump tables
*/

typedef	void	(*t_collf)(t_ray ray, void *obj, unsigned int *col, t_vec *hit);
t_collf			ft_coll_funct(int id);
typedef int		(*t_initf)(char *str, t_data *data, int i);
t_initf			ft_init_funct(int id);

unsigned long	ft_col_tohex(t_col col);
t_col			ft_col_torgb(unsigned long hex);
t_col			ft_col_init(void);
t_prop			ft_prop_init(void);

void			ft_mlx_img_to_win(t_data *data);
void			ft_mlx_pixel_to_img(t_data *data, int x,
				int y, unsigned int color);
int				ft_mlx_keypress(int keycode, void *param);
int				ft_mlx_render(t_data *data);
void			ft_mlx_pixtoimg(t_data *data, int x, int y, unsigned int col);
int				ft_mlx_init(t_data *data);
int				ft_bmp_render(t_data *data);

void			ft_cray_sphere(t_ray ray, void *obj,
				unsigned int *col, t_vec *hit);

/*
**Vector functions
*/
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

void			ft_data_clear(t_data *data);
void			ft_data_init(t_data *data);
int				ft_data_get(t_data *data, int fd);
int				ft_data_read(int fd, t_data *data, int i);
void			ft_data_print(t_data *data);

#endif
