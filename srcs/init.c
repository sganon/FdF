/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:42:13 by sganon            #+#    #+#             */
/*   Updated: 2016/02/22 12:01:30 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_struct(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (0);
	if (!(env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "FdF")))
		return (0);
	env->id = 1;
	env->size = 4;
	env->pitch = 4;
	env->spike = 1;
	env->pos_x = 250;
	env->pos_y = 150;
	env->ui = 1;
	env->image = NULL;
	env->image_addr = NULL;
	return (1);
}
