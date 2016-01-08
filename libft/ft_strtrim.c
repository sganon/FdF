/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:27:26 by sganon            #+#    #+#             */
/*   Updated: 2015/11/30 08:52:46 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	char		*str;
	char		*ret;

	if (s)
	{
		str = (char *)s;
		while (*str == ' ' || *str == '\n' || *str == '\t')
			str++;
		i = ft_strlen(str) - 1;
		if (ft_strlen(str) == 0)
			return (ret = ft_strnew(0));
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i--;
		if (!(ret = ft_strnew(i + 1)))
			return (NULL);
		j = -1;
		while (++j <= i)
			ret[j] = str[j];
		ret[j] = 0;
		return (ret);
	}
	return (NULL);
}
