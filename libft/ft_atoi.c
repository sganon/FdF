/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:50:27 by sganon            #+#    #+#             */
/*   Updated: 2015/12/01 14:23:38 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	negative;
	int	i;
	int	return_value;

	i = 0;
	negative = 0;
	return_value = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (ft_isdigit(str[i]) != 0)
	{
		return_value = (return_value * 10) - (str[i] - '0');
		i++;
	}
	if (!negative)
		return_value = -return_value;
	return (return_value);
}
