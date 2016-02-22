/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:37:35 by sganon            #+#    #+#             */
/*   Updated: 2016/01/04 13:20:52 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		length;
	int		i;

	length = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * length + 1);
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (++i < length)
		dest[i] = s1[i];
	dest[i] = '\0';
	return (dest);
}
