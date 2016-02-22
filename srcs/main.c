/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:59:22 by sganon            #+#    #+#             */
/*   Updated: 2016/02/22 13:03:41 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clean(t_env *env)
{
	t_point	p1;
	int		p;

	p1.y = 0;
	while (p1.y < WIN_Y)
	{
		p1.x = 0;
		while (p1.x < WIN_X)
		{
			p = p1.x * 4 + p1.y * env->size_line;
			env->image_addr[p] = 0;
			env->image_addr[p + 1] = 0;
			env->image_addr[p + 2] = 0;
			p1.x++;
		}
		p1.y++;
	}
}

int		expose_hook(t_env *env)
{
	if (env->image == NULL)
		create_image(env);
	ft_draw_image(env);
	mlx_put_image_to_window(env->mlx, env->win, env->image, 0, 0);
	if (env->ui == 1)
	{
		display_key(env);
		ft_display_variable(env);
	}
	mlx_do_sync(env->mlx);
	ft_clean(env);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*env;

	if (argc > 1 && argc <= 3)
	{
		env = (t_env *)malloc(sizeof(t_env));
		if (ft_strcmp(argv[1], "/dev/random") == 0)
			return (0);
		read_that_file(argv[1], env);
		if (init_struct(env) == 0 || env->map == NULL)
			return (0);
		if (argc == 3)
			check_argv(argv[2], env);
		mlx_key_hook(env->win, ft_key_hook, env);
		mlx_expose_hook(env->win, expose_hook, env);
		mlx_do_sync(env->mlx);
		mlx_loop(env->mlx);
	}
	ft_putendl("Too many arguments");
	return (0);
}
