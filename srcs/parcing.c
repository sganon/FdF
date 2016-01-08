/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:05:33 by sganon            #+#    #+#             */
/*   Updated: 2016/01/08 17:51:03 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_that_file(char *filename)
{
	int 	fd;
	char	*str;
	int 	ret;
	int		i;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return ;
	i = 0;
	while (42)
	{
		ret = get_next_line(fd, &str);
		if (ret == 1)
		{
			ft_putendl(str);
			free(str);
			i++;
		}
		else if (ret == -1)
			break;
		else
			break;
	}
}
