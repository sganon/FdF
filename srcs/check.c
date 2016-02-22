/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 12:12:41 by sganon            #+#    #+#             */
/*   Updated: 2016/02/22 13:02:51 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_ishexa(char c)
{
	if (ft_isdigit(c) || (c >= 'A' && c <= 'F') || c == 'x' || c == ',')
		return (1);
	else
		return (0);
}

int		check_for_char(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (env->tab[i])
	{
		j = 0;
		while (env->tab[i][j])
		{
			if (!ft_ishexa(env->tab[i][j])
			&& !ft_isspace(env->tab[i][j]) && env->tab[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_argv(char *arg, t_env *env)
{
	if (!ft_strcmp(arg, "mars"))
		env->id = 2;
	else
		env->id = 1;
}
