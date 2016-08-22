/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:36:43 by houlekhi          #+#    #+#             */
/*   Updated: 2016/08/12 19:52:58 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				get_color(t_env *e, int r, int g, int b)
{
	e->color.r = r;
	e->color.g = g;
	e->color.b = b;
}

void				fill_str2(t_env *e, int a, int b, int c)
{
	e->str[e->pos + 2] = a;
	e->str[e->pos + 1] = b;
	e->str[e->pos] = c;
}

void				fill_str3(t_env *e, int *j)
{
	
	if (e->sol == 1)
	{
		fill_str2(e, *j < 0 ? 0 : *j, *j < 0 ? 0 : *j, *j < 0 ? 0 : *j);
		*j -= 1;
	}
	else
		fill_str2(e, 50, 50, 50);
}

void				fill_str(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 255;
	e->i = 0;
	while (e->i < H)
	{
		e->pos = (e->i * e->size_line) + e->x * (e->bpp / 8);
		if (e->i < e->draw_start) 
		{
			e->str[e->pos + 2] = e->sky.str[e->pos + 2]; 
			e->str[e->pos + 1] = e->sky.str[e->pos + 1];
			e->str[e->pos] = e->sky.str[e->pos];
		}
		else if (e->i >= e->draw_start && e->i <= e->draw_end && e->lum == 1)
		{
			e->str[e->pos + 2] = (e->color.r + i > 255) ? 255 : e->color.r + i;
			e->str[e->pos + 1] = (e->color.g + i > 255) ? 255 : e->color.g + i;
			e->str[e->pos] = (e->color.b + i > 255) ? 255 : e->color.b + i;
			i++;
		}
		else if (e->i >= e->draw_start && e->i <= e->draw_end && e->lum == 0)
		{
			e->str[e->pos + 2] = e->color.r;
			e->str[e->pos + 1] = e->color.g;
			e->str[e->pos] = e->color.b;
		}
		else
		{
			e->str[e->pos + 2] = 0;
			e->str[e->pos + 1] = 65;
			e->str[e->pos] = 69;
		}
		e->i++;
	}
}
