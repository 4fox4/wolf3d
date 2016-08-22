/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:59:22 by houlekhi          #+#    #+#             */
/*   Updated: 2015/03/04 14:05:15 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				ft_tablen(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int				ft_nbline_infile(char const *str, t_env *e)
{
	int			i;
	int			fd;
	char		*line;

	i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line) > 0 || line[0] != '\0')
	{
		free(line);
		i++;
	}
	free(line);
	close(fd);
	e->y_max = i;
	return (i);
}

void			ft_free_tab_c(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int				*fill_line(int *line, char **tmp)
{
	int			j;

	j = 0;
	while (tmp[j])
	{
		line[j] = ft_atoi(tmp[j]);
		j++;
	}
	return (line);
}

int				**get_first_level(char *str, t_env *e)
{
	char		*line;
	char		**tmp;
	int			fd;
	int			i;

	e->map = (int **)malloc(sizeof(int *) * ft_nbline_infile(str, e));
	if (!e->map)
		return (NULL);
	i = 0;
	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) || line[0] != '\0')
	{
		tmp = ft_strsplit(line, ' ');
		e->map[i] = (int *)malloc(sizeof(int) * ft_tablen(tmp));
		if (!(e->map[i]))
			return (NULL);
		e->map[i] = fill_line(e->map[i], tmp);
		free(line);
		ft_free_tab_c(tmp);
		i++;
	}
	free(line);
	close(fd);
	return (e->map);
}
