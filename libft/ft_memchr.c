/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:48:05 by sganon            #+#    #+#             */
/*   Updated: 2015/12/01 14:01:01 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	k;

	if (n != 0)
	{
		k = (unsigned char)c;
		dest = (unsigned char *)s;
		while (n--)
		{
			if (*dest == k)
				return ((void *)dest);
			dest++;
		}
	}
	return (NULL);
}
