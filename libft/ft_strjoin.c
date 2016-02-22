/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:29:19 by sganon            #+#    #+#             */
/*   Updated: 2016/01/04 13:21:36 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	char	*dest2;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2)) + 1);
	if (dest == NULL)
		return (NULL);
	dest2 = dest;
	while (*s1)
		*dest2++ = *s1++;
	while (*s2)
		*dest2++ = *s2++;
	*dest2 = 0;
	return (dest);
}
