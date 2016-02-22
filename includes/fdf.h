/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:47:50 by sganon            #+#    #+#             */
/*   Updated: 2016/02/22 13:07:46 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

# define ESC			53
# define LEFT			123
# define RIGHT			124
# define UP				126
# define DOWN			125
# define MINUS			78
# define PLUS			69
# define KEY_C			8
# define STAR			67
# define SLASH			75

# define BLUE			0x0000FF
# define GREEN			0x00F611
# define BROWN			0x541919
# define WHITE			0xFFFFFF

# define WIN_X			1920
# define WIN_Y			1080

# define ABS(x)			((x) < 0 ? -(x) : (x))

# define ENDIAN			&(e->endian)
# define BBP			&(e->bbp)
# define PIKE			e->spike

typedef unsigned char	t_bytes;

typedef struct			s_rgb
{
	t_bytes				b;
	t_bytes				g;
	t_bytes				r;
}						t_rgb;

typedef union			u_color
{
	size_t				color;
	t_rgb				rgb;
}						t_color;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*image;
	char				*image_addr;
	int					id;
	int					size_line;
	int					bbp;
	int					endian;
	size_t				color;
	char				**tab;
	int					**map;
	t_point				**draw;
	int					x;
	int					y;
	int					pos_x;
	int					pos_y;
	double				spike;
	int					pitch;
	int					size;
	int					ui;
}						t_env;

void					ft_draw_border(t_env *env);
int						check_for_char(t_env *env);
void					ft_draw_image(t_env *env);
void					get_color(int y, int x, t_env *env);
void					ft_draw_border(t_env *env);
void					fill_image(t_env *env);
void					create_image(t_env *env);
void					read_that_file(char *filename, t_env *env);
int						**put_in_tab(char *str);
int						ft_key_hook(int keycode, t_env *env);
int						init_struct(t_env *env);
void					ft_draw_line(t_point p1, t_point p2, t_env *e);
int						expose_hook(t_env *env);
void					display_key(t_env *env);
void					ft_display_variable(t_env *env);
void					check_argv(char *arg, t_env *env);

#endif
