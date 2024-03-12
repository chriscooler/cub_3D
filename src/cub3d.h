#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include "../libft/libft.h"
# include <complex.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

# define WIDTH 1000
# define HEIGHT 1000
# define K_ESCAPE 53
# define N_WALLS 50000
// linux	
# define K_W				13
# define K_A				0
# define K_S				1
# define K_D				2
# define K_LEFT				123
# define K_RIGHT			124
# define K_ESCAPE 			53
# define MOUSE_SCROLL_UP 	4
# define MOUSE_SCROLL_DOWN	5
# define K_NUM_MULT			67
# define K_NUM_DIV			75
# define K_NUM_PLUS			69
# define K_NUM_MINUS		78
# define K_NUM_ENTER		76
# define K_NUM_0			82
# define K_UP				126
# define K_DOWN				125
# define K_LEFT				123
# define K_RIGHT			124
# define K_DIGIT_1			18
# define K_L				37
# define LEFT            	1
# define RIGHT           	2
# define MIDDLE          	3
# define SCROLLU         	4
# define SCROLLD         	5
# define ON_DESTROY			17
# define K_NUM_7			89
# define K_NUM_9			92
# define K_NUM_4			86
# define K_NUM_6			88
# define K_NUM_1			83
# define K_NUM_3			85

typedef struct s_K_data
{
	int			left;
	int			right;
	int			up;
	int			down;
	int			w;
	int			a;
	int			s;
	int			d;
	int			escape;
}				t_K_data;

typedef struct s_map
{
	int			**layout;
	double		walls[N_WALLS][2][2];
	double		fov;
	double		far;
	int			n_walls;
	int			m_x;
	int			m_y;
	int			t_w;
	int			t_h;
	void		*textures[4];
	int			*tex_data[4];
	int			tex_error;
	int			floor;
	int			ceil;
	double		c_pos[2];
	double		c_dir[2];
}				t_map;

typedef struct s_mlx
{
	void		*window;
	void		*img;
	char		*addr;
	int			endian;
	int			size_line;
	int			bits_per_pixel;
	t_K_data	keys;
	void		*mlx;
	t_map		*map;

}				t_mlx;

//input
void			rotate(t_mlx *env);
void			move(t_mlx *env);

/*/====compute : math=====/*/
//angle.c
void			rot_vec(double *v, double a, double *res);
double			get_ord_angle(double *v1);
double			get_abs_angle(double *v1);
double			get_angle(double *v1, double *v2);
void			polar_to_cart(double *v, double *res);

//compute.c
void			square_wall(double wall[][2][2], int x, int y);
void			convert_map_to_vecs(t_map *map);
void			scale_vec_to(double *v, double c, double *res);
void			inter_dist(double p[2][2], double v[2][2], double *dist,
					double *wall_x);
int				collide(t_map *map, double size);

//operators.c 
double			vec_cross(double *v1, double *v2);
void			sub_vec(double *v1, double *v2, double *res);
void			add_vec(double *v1, double *v2, double *res);
void			vec_mult(double *v, double c, double *res);
double			dot(double *v1, double *v2);

/*/====parsing : check map/texture/color====/*/
//colors.c
int				encode_rgb(int red, int green, int blue);
int				get_color(char *line);

//init_map.c
void			init_map(t_mlx *env);
void			init_layout(t_map *map);
int				get_camdir_pos(t_map *map, char card, int i, int j);
int				get_map(t_map *map, char *file);

//parsing.c
char			**fill_blank(t_map *map, char *file);
int				parse_input(t_mlx *env, char *config);
int				cw(char *s);

//textures.c
int				is_empty(char *s);
int				get_textures_colors(t_mlx *env, int fd, int count);
void			*open_tex(t_mlx *env, char *path, int idx);

//verify.c
void			vec_equal(double *v1, double *v2);
int				search(t_map *map, int **vis, int x, int y);
int				valid_size(t_map *map, char *file);
int				break_free(t_map *map);
int				m_x(t_map *map, char *file);

/*/====render : raycasting====/*/
//draw.c
int				det_cardinals(double wall[2][2]);
void			render_background(t_mlx *env);
void			set_pixel(t_mlx *env, int w_x, int w_y, int color);
void			draw_col_tex(t_mlx *env, int x, int idx, double *dists);

//minimap.c
void			draw_line(t_mlx *env, int *start, int *end, int color);
void			draw_circumf(t_mlx *env, int *pos, int r, int color);
void			draw_rest(t_mlx *env, int x, int y, int size);
void			draw_map_circle(t_mlx *env, int x, int y, int size);
void			draw_map(t_mlx *env, int x, int y, int size);

//render.c
void			draw_square(t_mlx *env, int *pos, int size, int color);
void			draw_circle(t_mlx *env, int *pos, int r, int color);
void			draw_closest_wall(t_mlx *env, double *ray, int x);
void			cast_rays(t_mlx *env);
int				frame(t_mlx *env);

//controls.c
void			init_keys(t_K_data *keys);
int				ft_press(int keycode, t_mlx *env);
int				ft_release(int keycode, t_mlx *env);

//main.c
int				exit_mlx(t_mlx *env);
void			*init_mlx_window(t_mlx *env, char *title);

#endif