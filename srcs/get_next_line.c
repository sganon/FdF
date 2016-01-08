/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:13:35 by sganon            #+#    #+#             */
/*   Updated: 2016/01/07 12:45:57 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*read_til_n(int const fd, char *ret)
{
	int			i;
	int			j;
	char		buf[BUFF_SIZE + 1];

	i = 0;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		j = 0;
		buf[i] = 0;
		if (ret)
			ret = ft_strjoin(ret, buf);
		else
			ret = ft_strdup(buf);
		while (buf[j])
		{
			if (buf[j] == '\n')
				return (ret);
			j++;
		}
	}
	if (i == -1)
		return (NULL);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char	*reste = NULL;
	char		*buf;
	int			i;

	i = 0;
	buf = NULL;
	if (!reste)
		reste = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (fd < 0 || fd == 1 || !line || !(buf = read_til_n(fd, reste)))
		return (-1);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (i > 0)
		reste = ft_strsub(buf, (i + 1), ft_strlen(buf));
	else if (i == 0 && buf[i] == '\n')
	{
		reste = ft_strsub(buf, 0, ft_strlen(buf));
		reste++;
	}
	else
		reste = NULL;
	*line = ft_strsub(buf, 0, i);
	if (i > 0 || (buf[i] == '\n' && i == 0))
		return (1);
	return (0);
}
