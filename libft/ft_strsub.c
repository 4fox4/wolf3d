/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houlekhi <houlekhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:02:35 by houlekhi          #+#    #+#             */
/*   Updated: 2014/11/22 17:32:54 by houlekhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	if (s == NULL)
		return (NULL);
	dest = ft_strnew(len + 1);
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (i < len + start)
	{
		if (i >= start)
			dest[i - start] = s[i];
		i++;
	}
	return (dest);
}
