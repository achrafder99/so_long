/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:40:03 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 17:25:07 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	update_vars(t_vars *vars, int i, int j)
{
	if (vars->represent_env[i][j] == 'N')
	{
		vars->number_of_enemy++;
		vars->represent_env[i][j] = '0';
	}
	return (0);
}

int	check_surrounding_cells(t_vars *vars)
{
	int	i;
	int	j;

	i = get_position_x(vars->represent_env);
	j = get_position_y(vars->represent_env);
	update_vars(vars, i, j - 1);
	update_vars(vars, i, j + 1);
	update_vars(vars, i - 1, j);
	update_vars(vars, i + 1, j);
	return (0);
}

int	kill(int mouse, int x, int y, void *params)
{
	t_vars	*vars;

	(void)mouse;
	(void)x;
	(void)y;
	vars = (t_vars *)params;
	check_surrounding_cells(vars);
	return (0);
}
