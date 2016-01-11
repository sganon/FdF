/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 17:05:33 by sganon            #+#    #+#             */
/*   Updated: 2016/01/11 16:01:55 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_that_file(char *filename)
{
	int 	fd;
	char	*str;
	char	*tmp;
	int 	ret;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (NULL);
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
		return (NULL);
	else
		return (tmp);
}

int		get_width(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		get_height(char *str)
{
	int width;

	width = get_width(str);
	return (width / ft_strlen(str));
}

int		**put_in_tab(char *str)
{
	int		**ret;

	ret = (int **)malloc(sizeof(int *) * get_heigth(str));
	while (i <= get_height)
	{
		ret[i] = (int *)malloc(sizeof(int) * get_width(str));
		ret[i] 
	}
	return (ret);
}
