/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:33:11 by sganon            #+#    #+#             */
/*   Updated: 2016/01/28 18:24:16 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_key(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 0, 0, WHITE, "ESC to quit");
	mlx_string_put(env->mlx, env->win, 0, 30, WHITE, "Use arrows to move");
	mlx_string_put(env->mlx, env->win, 0, 60, WHITE, "+ & - to resize");
	mlx_string_put(env->mlx, env->win, 0, 90, WHITE, "* & / to resize pikes");
	mlx_string_put(env->mlx, env->win, WIN_X - 93, 0, WHITE, "C to hide");
}

void	ft_display_variable(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 0, 150, WHITE, "Size: ");
	mlx_string_put(env->mlx, env->win, 70, 150, WHITE, ft_itoa(env->size));
	mlx_string_put(env->mlx, env->win, 0, 180, WHITE, "X0: ");
	mlx_string_put(env->mlx, env->win, 70, 180, WHITE, ft_itoa(env->pos_x));
	mlx_string_put(env->mlx, env->win, 0, 210, WHITE, "Y0: ");
	mlx_string_put(env->mlx, env->win, 70, 210, WHITE, ft_itoa(env->pos_y));
}
