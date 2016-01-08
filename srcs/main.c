/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:59:22 by sganon            #+#    #+#             */
/*   Updated: 2016/01/08 17:39:06 by sganon           ###   ########.fr       */
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
	read_that_file(argv[1]);
	if(!(env->mlx = mlx_init()))
		return (0);
	env->win = mlx_new_window(env->mlx, 420, 420, "FdF");
	sleep(10);
	return (0);
}
