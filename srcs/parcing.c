/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:05:33 by sganon            #+#    #+#             */
/*   Updated: 2016/01/12 15:22:18 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_that_file(char *filename, t_env *env)
{
	int 	fd;
	char	*str;
	char	*tmp;
	int 	ret;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return ;
	tmp = "";
	while (42)
	{
		ret = get_next_line(fd, &str);
		if (ret == 1)
		{
			tmp = ft_strjoin(tmp, str);
			tmp[ft_strlen(tmp)] = '\n';
		}
		else if (ret == -1)
			break ;
		else
			break ;
	}
	if (ret == -1)
		return ;
	else
		env->tab = ft_strsplit(tmp, '\n');
}
