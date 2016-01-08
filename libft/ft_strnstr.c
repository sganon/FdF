/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:27:39 by sganon            #+#    #+#             */
/*   Updated: 2015/12/01 14:19:55 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (s2[0] == 0)
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			while (s2[j] && s1[i + j] == s2[j] && (i + j) < n)
				j++;
			if (s2[j] == 0)
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
