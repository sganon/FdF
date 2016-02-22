/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:26:38 by sganon            #+#    #+#             */
/*   Updated: 2016/01/28 18:00:31 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_y_border(t_env *e)
{
	int		y;
	int		x;
	t_point	p1;
	t_point	p2;
	int		xx;

	y = 0;
	while (y < e->y - 1)
	{
		x = e->x - 1;
		xx = e->pos_x - (y * e->size / 2);
		get_color(y, x, e);
		p1.y = e->pos_y + (y * e->size - (e->map[y][x] * e->spike));
		p1.x = xx + x * e->size;
		p2.y = e->pos_y + ((y + 1) * e->size - (e->map[y + 1][x] * e->spike));
		p2.x = e->pos_x - ((y + 1) * e->size / 2) + x * e->size;
		ft_draw_line(p1, p2, e);
		y++;
	}
}

static void	ft_draw_x_border(t_env *e)
{
	int		y;
	int		x;
	t_point	p1;
	t_point p2;
	int		xx;

	y = e->y - 1;
	x = 0;
	xx = e->pos_x - (y * e->size / 2);
	while (x < e->x - 1)
	{
		get_color(y, x, e);
		p1.y = e->pos_y + (y * e->size - (e->map[y][x] * e->spike));
		p1.x = xx + x * e->size;
		p2.y = e->pos_y + (y * e->size - (e->map[y][x + 1] * e->spike));
		p2.x = xx + (x + 1) * e->size;
		ft_draw_line(p1, p2, e);
		x++;
	}
}

void		ft_draw_border(t_env *env)
{
	ft_draw_y_border(env);
	ft_draw_x_border(env);
}
