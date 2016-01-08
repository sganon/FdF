/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:34:24 by sganon            #+#    #+#             */
/*   Updated: 2015/11/30 08:39:03 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	if (s && f)
	{
		i = 0;
		if (!(dest = ft_strdup(s)))
			return (NULL);
		while (dest[i])
		{
			dest[i] = f(dest[i]);
			i++;
		}
		return (dest);
	}
	return (NULL);
}
