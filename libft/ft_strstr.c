/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:27:09 by sganon            #+#    #+#             */
/*   Updated: 2015/12/01 14:19:14 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	if (s2[0] == 0)
		return ((char *)s1);
	while (s1[i])
	{
		j = i;
		k = 0;
		while (s1[j] == s2[k])
		{
			j++;
			k++;
			if (s2[k] == 0)
				return (char *)(&s1[i]);
		}
		i++;
	}
	return (NULL);
}
