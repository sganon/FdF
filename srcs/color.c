/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:01:49 by sganon            #+#    #+#             */
/*   Updated: 2016/02/22 13:01:52 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_color1(int y, int x, t_env *env)
{
	if (env->map[y][x] <= 0)
		env->color = BLUE;
	else if (env->map[y][x] > 0 && env->map[y][x] <= 40)
		env->color = GREEN;
	else if (env->map[y][x] > 40 && env->map[y][x] <= 120)
		env->color = BROWN;
	else
		env->color = WHITE;
}

void	get_color2(int y, int x, t_env *env)
{
	t_color u;

	u.rgb.r = (env->map[y][x] * 10);
	if (u.rgb.r <= 60)
		u.rgb.r = 60;
	if (u.rgb.r > 255)
		u.rgb.r = 255;
	u.rgb.b = 0;
	u.rgb.g = 0;
	env->color = u.color;
}

void	get_color(int y, int x, t_env *env)
{
	if (env->id == 1)
		get_color1(y, x, env);
	else if (env->id == 2)
		get_color2(y, x, env);
	else
		get_color1(y, x, env);
}
