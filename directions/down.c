/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:50:58 by adardour          #+#    #+#             */
/*   Updated: 2023/02/13 16:06:40 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	eat_collect(t_vars *vars)
{
	vars->represent_env[vars->player_x][vars->player_y] = '0';
	vars->represent_env[vars->player_x + 1][vars->player_y] = 'P';
	vars->how_much_collect--;
	return (ft_putnbr_fd(vars->moves, 1), ft_putchar_fd('\n', 1));
}

void	down(t_vars *vars)
{
	char	next_cell;

	vars->player_x = get_position_x(vars->represent_env);
	vars->player_y = get_position_y(vars->represent_env);
	next_cell = vars->represent_env[vars->player_x + 1][vars->player_y];
	if (next_cell != '1' && next_cell != 'E')
	{
		vars->moves++;
		if (next_cell == 'C')
			eat_collect(vars);
		else if (next_cell == '0' || next_cell == 'N')
		{
			if (next_cell == 'N')
				return (printf("Your lose\n"), exit(EXIT_FAILURE));
			vars->represent_env[vars->player_x][vars->player_y] = '0';
			vars->represent_env[vars->player_x + 1][vars->player_y] = 'P';
			return (ft_putnbr_fd(vars->moves, 1), ft_putchar_fd('\n', 1));
		}
	}
	else if (next_cell == 'E' && (vars->how_much_collect == 0))
		return (show_info(), exit(EXIT_SUCCESS));
}
