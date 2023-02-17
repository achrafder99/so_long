/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:40:12 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 17:27:44 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_valid_to_move(int x, int y, t_vars *vars)
{
	return ((x > 0) && (x < get_lines(vars->path)) && (y > 0)
		&& (y < get_column(vars->represent_env))
		&& (vars->represent_env[x][y] != '1'
		&& vars->represent_env[x][y] != 'E'));
}

int	found_destination(int x, int y, int dx, int dy)
{
	return ((x == dx) && (y == dy));
}

int	backtracking(int x, int y, t_vars *vars)
{
	if (found_destination(x, y, vars->positions.dx, vars->positions.dy))
	{
		vars->visited[x][y] = '1';
		return (1);
	}
	if (!is_valid_to_move(x, y, vars) || vars->visited[x][y] == '1')
		return (0);
	vars->visited[x][y] = '1';
	if (backtracking(x - 1, y, vars))
		return (1);
	if (backtracking(x + 1, y, vars))
		return (1);
	if (backtracking(x, y - 1, vars))
		return (1);
	if (backtracking(x, y + 1, vars))
		return (1);
	return (0);
}
