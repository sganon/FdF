/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:36:56 by sganon            #+#    #+#             */
/*   Updated: 2016/01/28 18:06:45 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_program(int keycode, void *param)
{
	if (keycode == ESC)
	{
		(void)param;
		exit(0);
		return (1);
	}
	return (0);
}

int		handle_size(int keycode, t_env *env)
{
	if (keycode == MINUS)
	{
		env->size = env->size / 2;
		env->pos_x = env->pos_x - 25;
		if (env->size < 1)
			env->size = 1;
		expose_hook(env);
	}
	else if (keycode == PLUS)
	{
		env->size = env->size * 2;
		env->pos_x = env->pos_x + 25;
		if (env->size > 100)
			env->size = 100;
		expose_hook(env);
	}
	return (0);
}

int		handle_pos(int keycode, t_env *env)
{
	if (keycode == LEFT)
	{
		env->pos_x = env->pos_x - 10;
		expose_hook(env);
	}
	else if (keycode == RIGHT)
	{
		env->pos_x = env->pos_x + 10;
		expose_hook(env);
	}
	else if (keycode == UP)
	{
		env->pos_y = env->pos_y - 10;
		expose_hook(env);
	}
	else if (keycode == DOWN)
	{
		env->pos_y = env->pos_y + 10;
		expose_hook(env);
	}
	return (0);
}

int		handle_spike(int keycode, t_env *env)
{
	if (keycode == STAR)
	{
		env->spike = env->spike + 0.1;
		if (env->spike == 10)
			env->spike = 10;
		expose_hook(env);
	}
	else if (keycode == SLASH)
	{
		env->spike = env->spike - 0.1;
		if (env->spike == 0)
			env->spike = 0.1;
		expose_hook(env);
	}
	return (0);
}

int		ft_key_hook(int keycode, t_env *env)
{
	if (keycode == ESC)
		exit_program(keycode, 0);
	else if (keycode == MINUS || keycode == PLUS)
		handle_size(keycode, env);
	else if (keycode == LEFT || keycode == RIGHT
			|| keycode == UP || keycode == DOWN)
		handle_pos(keycode, env);
	else if (keycode == SLASH || keycode == STAR)
		handle_spike(keycode, env);
	else if (keycode == KEY_C)
	{
		env->ui = !env->ui ? 1 : 0;
		expose_hook(env);
	}
	return (0);
}
