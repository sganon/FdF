/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:15:48 by sganon            #+#    #+#             */
/*   Updated: 2015/11/26 19:37:27 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (i < n)
		{
			if (s1[i] != s2[i])
				return (0);
			if (s1[i] == 0 && s2[i] == 0)
				return (1);
			i++;
		}
		return (1);
	}
	return (0);
}
