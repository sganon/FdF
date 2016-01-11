/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:47:50 by sganon            #+#    #+#             */
/*   Updated: 2016/01/11 14:03:56 by sganon           ###   ########.fr       */
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

char	*read_that_file(char *filename);
int		**put_in_tab(char *str);
int		exit_program(int keycode, void *param);

#endif
