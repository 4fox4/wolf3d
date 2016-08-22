/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 13:48:31 by houlekhi          #+#    #+#             */
/*   Updated: 2015/06/11 16:45:13 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(void)
{
	t_env	e;

	if (!(e.mlx = mlx_init()))
		error("Give me an valid environment");
	e.tab = get_first_level("map_test", &e);
	e.window = mlx_new_window(e.mlx, W, H, "wolf3d");
	system("afplay wolf_sound.mp3 &");
	ft_init(&e);
	raycaster(&e);
	mlx_expose_hook(e.window, expose_hook, &e);
	mlx_hook(e.window, 2, 3, key_hook, &e);
	mlx_loop(e.mlx);
	return (1);
}
