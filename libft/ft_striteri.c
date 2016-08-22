/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 15:05:01 by houlekhi          #+#    #+#             */
/*   Updated: 2014/11/22 17:45:12 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	len;
	int	i;

	if (s != NULL && f != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
