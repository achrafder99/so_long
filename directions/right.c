/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:52:02 by adardour          #+#    #+#             */
/*   Updated: 2023/02/13 16:06:53 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_vars *vars, int x, int y)
{
	if (vars->represent_env[x][y + 1] == '1')
		return ;
	if (vars->represent_env[x][y + 1] == 'C')
	{
		vars->represent_env[x][y] = '0';
		vars->represent_env[x][y + 1] = 'P';
		vars->how_much_collect--;
		vars->moves++;
		ft_putnbr_fd(vars->moves, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (vars->represent_env[x][y + 1] == '0')
	{
		vars->represent_env[x][y + 1] = 'P';
		vars->represent_env[x][y] = '0';
		vars->moves++;
		ft_putnbr_fd(vars->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	check_right_collision(t_vars *vars, int x, int y)
{
	if (vars->represent_env[x][y + 1] == 'N')
	{
		printf("Your lose\n");
		exit(EXIT_FAILURE);
	}
	else if (vars->represent_env[x][y + 1] == 'E'
			&& vars->how_much_collect == 0)
	{
		show_info();
		exit(EXIT_SUCCESS);
	}
}

void	right(t_vars *vars)
{
	int	x;
	int	y;

	x = get_position_x(vars->represent_env);
	y = get_position_y(vars->represent_env);
	move_right(vars, x, y);
	check_right_collision(vars, x, y);
}
