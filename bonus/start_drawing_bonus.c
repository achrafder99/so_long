/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_drawing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:10:21 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 21:08:36 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_walls(int x, int y, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.walls.img, x, y);
}

void	draw_player(int x, int y, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor.img, x, y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player.img, x, y);
}

void	draw_exit(int x, int y, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor.img, x, y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit_close.img, x,
		y);
}

int	draw_elements(t_vars *vars, int x, int y, char element)
{
	if (element == '1')
		draw_walls(x, y, vars);
	if (element == 'P')
		draw_player(x, y, vars);
	if (element == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor.img, x,
			y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.collect.img, x,
			y);
	}
	if (element == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor.img, x,
			y);
	if (element == 'E')
		draw_exit(x, y, vars);
	if (element == 'N')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor.img, x,
			y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.enemy.img, x,
			y);
	}
	return (0);
}

int	start_drawing_bonus(t_vars *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (vars->represent_env[i] != NULL)
	{
		j = 0;
		x = 0;
		while (vars->represent_env[i][j] != '\0')
		{
			draw_elements(vars, x, y, vars->represent_env[i][j]);
			j++;
			x += 50;
		}
		i++;
		y += 50;
		show_moves(vars);
	}
	return (0);
}
