/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:49:59 by adardour          #+#    #+#             */
/*   Updated: 2023/02/13 16:06:50 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_up(t_vars *vars, int x, int y)
{
	if (vars->represent_env[x - 1][y] == '1')
		return ;
	if (vars->represent_env[x - 1][y] == 'C')
	{
		vars->represent_env[x][y] = '0';
		vars->represent_env[x - 1][y] = 'P';
		vars->how_much_collect--;
		vars->moves++;
		ft_putnbr_fd(vars->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (vars->represent_env[x - 1][y] == '0')
	{
		vars->represent_env[x - 1][y] = 'P';
		vars->represent_env[x][y] = '0';
		vars->moves++;
		ft_putnbr_fd(vars->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

static void	check_up_collision(t_vars *vars, int x, int y)
{
	if (vars->represent_env[x - 1][y] == 'N')
	{
		printf("Your lose\n");
		exit(EXIT_FAILURE);
	}
	else if (vars->represent_env[x - 1][y] == 'E'
			&& vars->how_much_collect == 0)
	{
		show_info();
		exit(EXIT_SUCCESS);
	}
}

void	up(t_vars *vars)
{
	int	x;
	int	y;

	x = get_position_x(vars->represent_env);
	y = get_position_y(vars->represent_env);
	move_up(vars, x, y);
	check_up_collision(vars, x, y);
}
