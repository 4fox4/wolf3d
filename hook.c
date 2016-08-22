/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 11:32:49 by houlekhi          #+#    #+#             */
/*   Updated: 2015/06/11 18:09:54 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_free_tab_i(int **tab, int max)
{
	int		i;

	i = 0;
	while (i < max)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		key_hook2(int keycode, t_env *e)
{
	double tmp;

	tmp = e->rot_speed;
	e->rot_speed = 1.570796;
	if (keycode == KEY_NUM_5 && e->hgth < H)
		e->hgth += 5;
	else if (keycode == KEY_NUM_2 && e->hgth > H / 4)
		e->hgth -= 5;
	else if (keycode == 37)
		e->lum = (e->lum == 1) ? 0 : 1;
	else if (keycode == 1)
		e->sol = (e->sol == 1) ? 0 : 1;
	else if (keycode == KEY_NUM_1)
	{
		key_left(e);
		key_up(e);
		key_right(e);
	}
	else if (keycode == KEY_NUM_3)
	{
		key_right(e);
		key_up(e);
		key_left(e);
	}
	e->rot_speed = tmp;
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		ft_free_tab_i(e->map, e->y_max);
		system("killall afplay &");
		exit(0);
	}
	else if (keycode >= KEY_LEFT && keycode <= KEY_UP)
		key_move(e, keycode);
	else if (keycode == 0)
		e->move_speed = e->move_speed == 0.3 ? 0.8 : 0.3;
	else
		key_hook2(keycode, e);
	raycaster(e);
	return (0);
}

int			expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->window, e->img, 0, 0);
	return (0);
}
