/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:47:25 by sganon            #+#    #+#             */
/*   Updated: 2015/12/08 15:52:53 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char				*dest;
	unsigned int		i;

	i = 0;
	dest = (char *)malloc(len * sizeof(char) + 1);
	if (s && len > 0)
	{
		if (dest == NULL || s == NULL)
			return (NULL);
		while (s[start] && i < len)
		{
			dest[i] = s[start];
			i++;
			start++;
		}
		dest[i] = 0;
	}
	return (dest);
}
