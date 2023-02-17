/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:52:56 by adardour          #+#    #+#             */
/*   Updated: 2023/02/13 16:07:09 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_position(t_vars *vars)
{
	vars->player_x = get_position_x(vars->represent_env);
	vars->player_y = get_position_y(vars->represent_env);
	if (vars->represent_env[vars->player_x][vars->player_y - 1] != '1' &&
		vars->represent_env[vars->player_x][vars->player_y - 1] != 'E')
	{
		vars->moves++;
		if (vars->represent_env[vars->player_x][vars->player_y - 1] == 'C')
		{
			vars->represent_env[vars->player_x][vars->player_y - 1] = 'P';
			vars->represent_env[vars->player_x][vars->player_y] = '0';
			vars->how_much_collect--;
			ft_putnbr_fd(vars->moves, 1);
			ft_putchar_fd('\n', 1);
		}
		else if (vars->represent_env[vars->player_x][vars->player_y - 1] == '0')
		{
			vars->represent_env[vars->player_x][vars->player_y - 1] = 'P';
			vars->represent_env[vars->player_x][vars->player_y] = '0';
			ft_putnbr_fd(vars->moves, 1);
			ft_putchar_fd('\n', 1);
		}
	}
}

void	check_win_lose(t_vars *vars)
{
	if (vars->represent_env[vars->player_x][vars->player_y - 1] == 'N')
	{
		printf("Your lose\n");
		exit(EXIT_FAILURE);
	}
	else if (vars->represent_env[vars->player_x][vars->player_y - 1] == 'E' &&
				vars->how_much_collect == 0)
	{
		show_info();
		exit(EXIT_SUCCESS);
	}
}

void	left(t_vars *vars)
{
	update_position(vars);
	check_win_lose(vars);
}
