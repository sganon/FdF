/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:47:50 by sganon            #+#    #+#             */
/*   Updated: 2016/01/09 17:06:24 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			**tab;
}					t_env;

void	read_that_file(char *filename, t_env *env);
int		exit_program(int keycode, void *param);

#endif
