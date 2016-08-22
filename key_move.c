/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 13:45:44 by houlekhi          #+#    #+#             */
/*   Updated: 2015/06/11 18:29:32 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		key_up(t_env *e)
{
	double	tmp_u;
	double	tmp_u2;

	tmp_u = e->pos_x + e->dir_x * e->move_speed;
	tmp_u2 = e->pos_y + e->dir_y * e->move_speed;
	if (e->tab[(int)(tmp_u)][(int)(e->pos_y)] == 0)
		e->pos_x = tmp_u;
	if (e->tab[(int)(e->pos_x)][(int)(tmp_u2)] == 0)
		e->pos_y = tmp_u2;
}

void		key_down(t_env *e)
{
	double	tmp_d;
	double	tmp_d2;

	tmp_d = e->pos_x - e->dir_x * e->move_speed;
	tmp_d2 = e->pos_y - e->dir_y * e->move_speed;
	if (e->tab[(int)(tmp_d)][(int)(e->pos_y)] == 0)
		e->pos_x = tmp_d;
	if (e->tab[(int)(e->pos_x)][(int)(tmp_d2)] == 0)
		e->pos_y = tmp_d2;
}

void		key_left(t_env *e)
{
	double	cos_l;
	double	sin_l;

	cos_l = cos(e->rot_speed);
	sin_l = sin(e->rot_speed);
	e->old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos_l - e->dir_y * sin_l;
	e->dir_y = e->old_dir_x * sin_l + e->dir_y * cos_l;
	e->old_plane_x = e->plane_x;
	e->plane_x = e->plane_x * cos_l - e->plane_y * sin_l;
	e->plane_y = e->old_plane_x * sin_l + e->plane_y * cos_l;
}

void		key_right(t_env *e)
{
	double	cos_r;
	double	sin_r;

	cos_r = cos(-e->rot_speed);
	sin_r = sin(-e->rot_speed);
	e->old_dir_x = e->dir_x;
	e->dir_x = e->dir_x * cos_r - e->dir_y * sin_r;
	e->dir_y = e->old_dir_x * sin_r + e->dir_y * cos_r;
	e->old_plane_x = e->plane_x;
	e->plane_x = e->plane_x * cos_r - e->plane_y * sin_r;
	e->plane_y = e->old_plane_x * sin_r + e->plane_y * cos_r;
}

void		key_move(t_env *e, int keycode)
{
	if (keycode == KEY_UP)
		key_up(e);
	if (keycode == KEY_DOWN)
		key_down(e);
	if (keycode == KEY_RIGHT)
		key_right(e);
	if (keycode == KEY_LEFT)
		key_left(e);
}
