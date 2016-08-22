/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:13:56 by houlekhi          #+#    #+#             */
/*   Updated: 2015/06/11 18:12:56 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	init_img(t_env *e)
{
	char	*skybox;

	skybox = "etoile.xpm";
	if (!(e->img = mlx_new_image(e->mlx, W, H)))
		error("Enable to create image");
	if (!(e->str = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, \
																&e->endian)))
		error("Enable to load image data");
	if (!(e->sky.img = mlx_xpm_file_to_image(e->mlx, skybox, &e->wght, &e->h)))
		error("Enable to load image data skybox");
	if (!(e->sky.str = mlx_get_data_addr(e->sky.img, &e->sky.bpp, \
											&e->sky.size_line, &e->sky.endian)))
		error("Enable to load image data");
}

void	ft_init(t_env *e)
{
	e->lum = 0;
	e->sol = 0;
	e->pos_x = 22;
	e->pos_y = 12;
	e->dir_x = -1;
	e->dir_y = 0;
	e->plane_x = 0;
	e->plane_y = 0.66;
	e->move_speed = 0.3;
	e->rot_speed = 0.06;
	e->pos = 0;
	e->i = 0;
	e->changed = 0;
	e->hgth = H / 2;
	init_img(e);
}
