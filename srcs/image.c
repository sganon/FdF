/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:18:08 by sganon            #+#    #+#             */
/*   Updated: 2016/02/22 13:01:44 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_color_in_image(t_env *env, int x, int y)
{
	t_color	u;
	int		p;

	u.color = env->color;
	p = x * 4 + y * env->size_line;
	if (y > 0 && y < WIN_Y && x > 0 && x < WIN_X)
	{
		env->image_addr[p] = u.rgb.b;
		env->image_addr[p + 1] = u.rgb.g;
		env->image_addr[p + 2] = u.rgb.r;
	}
}

void	create_image(t_env *e)
{
	e->endian = 0;
	e->bbp = 8;
	e->size_line = WIN_X;
	e->image = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->image_addr = mlx_get_data_addr(e->image, BBP, &(e->size_line), ENDIAN);
}

void	ft_draw_line(t_point p1, t_point p2, t_env *e)
{
	t_point		d;
	t_point		s;
	int			err;
	int			e2;

	d.x = ABS(p2.x - p1.x);
	d.y = ABS(p2.y - p1.y);
	s.x = p1.x < p2.x ? 1 : -1;
	s.y = p1.y < p2.y ? 1 : -1;
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (42)
	{
		draw_color_in_image(e, p1.x, p1.y);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = err;
		if (e2 > -d.x && ((err -= d.y) || !err))
			p1.x += s.x;
		if (e2 < d.y)
		{
			err += d.x;
			p1.y += s.y;
		}
	}
}

void	ft_draw_image(t_env *e)
{
	int		y;
	int		x;
	t_point	p1;
	t_point	p2;
	int		xx;

	y = -1;
	while (++y < e->y - 1)
	{
		x = -1;
		xx = e->pos_x - (y * e->size / 2);
		while (++x < e->x - 1)
		{
			get_color(y, x, e);
			p1.y = e->pos_y + (y * e->size - (e->map[y][x] * PIKE));
			p1.x = xx + x * e->size;
			p2.y = e->pos_y + ((y + 1) * e->size - (e->map[y + 1][x] * PIKE));
			p2.x = e->pos_x - ((y + 1) * e->size / 2) + x * e->size;
			ft_draw_line(p1, p2, e);
			p2.y = e->pos_y + (y * e->size - (e->map[y][x + 1] * PIKE));
			p2.x = xx + (x + 1) * e->size;
			ft_draw_line(p1, p2, e);
		}
	}
	ft_draw_border(e);
}
