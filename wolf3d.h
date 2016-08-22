/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:59:15 by houlekhi          #+#    #+#             */
/*   Updated: 2015/12/30 23:24:03 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
// # include "minilibx/mlx_int.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_MULT 67
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_DIV 75
# define KEY_NUM_0 82
# define KEY_NUM_1 83
# define KEY_NUM_2 84
# define KEY_NUM_3 85
# define KEY_NUM_4 86
# define KEY_NUM_5 87
# define KEY_NUM_6 88
# define KEY_NUM_7 89
# define KEY_NUM_8 91
# define KEY_NUM_9 92
# define H 			768
# define W 			1024

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_sky
{
	void			*img;
	char			*str;
	int				bpp;
	int				size_line;
	int				endian;
}					t_sky;

typedef struct		s_env
{
	void			*mlx;
	void			*window;
	int				**tab;

	int				**map;
	int				i;
	int				pos;

	void			*img;
	char			*str;
	int				bpp;
	int				size_line;
	int				endian;

	struct s_sky	sky;
	int				wght;
	int				h;

	struct s_color	color;

	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				x;
	int				w;
	double			camera_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
	double			time;
	double			old_time;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
	double			old_dir_x;
	double			old_plane_x;
	int				hgth;

	int				y_max;
	int				keycode;
	int				changed;
	int				lum;
	int				sol;
}					t_env;

int					**get_first_level(char *str, t_env *e);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				ft_init(t_env *e);
void				verline(t_env *e);
void				fill_str(t_env *e);
void				raycaster(t_env *e);
void				get_color(t_env *e, int r, int g, int b);
void				init_img(t_env *e);
void				error(char *str);
void				key_move(t_env *e, int keycode);
void				key_up(t_env *e);
void				key_down(t_env *e);
void				key_left(t_env *e);
void				key_right(t_env *e);

#endif
