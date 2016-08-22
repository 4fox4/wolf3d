/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:47:07 by houlekhi          #+#    #+#             */
/*   Updated: 2016/08/12 19:48:15 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				raycast_init(t_env *e)
{
	double			raydirx;
	double			raydiry;

	e->camera_x = 2 * e->x / (double)W - 1;
	e->ray_pos_x = e->pos_x;
	e->ray_pos_y = e->pos_y;
	e->ray_dir_x = e->dir_x + e->plane_x * e->camera_x;
	e->ray_dir_y = e->dir_y + e->plane_y * e->camera_x;
	raydirx = e->ray_dir_x * e->ray_dir_x;
	raydiry = e->ray_dir_y * e->ray_dir_y;
	e->map_x = (int)e->ray_pos_x;
	e->map_y = (int)e->ray_pos_y;
	e->delta_dist_x = sqrt(1 + raydiry / raydirx);
	e->delta_dist_y = sqrt(1 + raydirx / raydiry);
	e->hit = 0;
}

void				init_side(t_env *e)
{
	if (e->ray_dir_x < 0)
	{
		e->step_x = -1;
		e->side_dist_x = (e->ray_pos_x - e->map_x) * e->delta_dist_x;
	}
	else
	{
		e->step_x = 1;
		e->side_dist_x = (e->map_x + 1.0 - e->ray_pos_x) * e->delta_dist_x;
	}
	if (e->ray_dir_y < 0)
	{
		e->step_y = -1;
		e->side_dist_y = (e->ray_pos_y - e->map_y) * e->delta_dist_y;
	}
	else
	{
		e->step_y = 1;
		e->side_dist_y = (e->map_y + 1.0 - e->ray_pos_y) * e->delta_dist_y;
	}
}

void				hit_side(t_env *e)
{
	while (e->hit == 0)
	{
		if (e->side_dist_x < e->side_dist_y)
		{
			e->side_dist_x += e->delta_dist_x;
			e->map_x += e->step_x;
			e->side = 0;
		}
		else
		{
			e->side_dist_y += e->delta_dist_y;
			e->map_y += e->step_y;
			e->side = 1;
		}
		if (e->tab[e->map_x][e->map_y] > 0)
			e->hit = 1;
	}
}

void				make_wall_color(t_env *e)
{
	if (e->side == 0)
		e->perp_wall_dist = \
		fabs((e->map_x - e->ray_pos_x + (1 - e->step_x) / 2) / e->ray_dir_x);
	else
		e->perp_wall_dist = \
		fabs((e->map_y - e->ray_pos_y + (1 - e->step_y) / 2) / e->ray_dir_y);
	e->line_height = abs((int)(H / e->perp_wall_dist));
	e->draw_start = -e->line_height / 2 + e->hgth;
	if (e->draw_start < 0)
		e->draw_start = 0;
	e->draw_end = e->line_height / 2 + e->hgth;
	if (e->draw_end >= H)
		e->draw_end = H - 1;
	if (e->side == 0 && e->ray_dir_x > 0)
		get_color(e, 0, 150, 136);
	else if (e->side == 0 && e->ray_dir_x < 0)
		get_color(e, 0, 179, 161);
	else if (e->side == 1 && e->ray_dir_y > 0)
		get_color(e, 0, 94, 84);
	else
		get_color(e, 0, 126, 110);
}

void				raycaster(t_env *e)
{
	mlx_clear_window(e->mlx, e->window);
	e->x = 0;
	while (e->x < W)
	{
		raycast_init(e);
		init_side(e);
		hit_side(e);
		make_wall_color(e);
		fill_str(e);
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->window, e->img, 0, 0);
}
