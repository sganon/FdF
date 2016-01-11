/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:59:22 by sganon            #+#    #+#             */
/*   Updated: 2016/01/11 12:48:04 by sganon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_env	*env;

	(void)argc;
	(void)argv;

	env = (t_env *)malloc(sizeof(t_env));
	ft_put_tab(put_in_tab(read_that_file(argv[1])));
	if(!(env->mlx = mlx_init()))
		return (0);
	env->win = mlx_new_window(env->mlx, 1920, 1080, "FdF");
	mlx_string_put(env->mlx, env->win, 0, 0, 0x00FFFF, "ESC to quit");
	mlx_key_hook(env->win, exit_program, 0);
	mlx_loop(env->mlx);
	return (0);
}
