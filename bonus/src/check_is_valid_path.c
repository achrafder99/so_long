/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:40:33 by adardour          #+#    #+#             */
/*   Updated: 2023/02/15 22:48:15 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	reset_visited(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < get_lines(vars->path))
	{
		j = 0;
		while (j < get_column(vars->represent_env))
		{
			vars->visited[i][j] = '0';
			j++;
		}
		i++;
	}
}

void	find_exit_position(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->represent_env[i] != NULL)
	{
		j = 0;
		while (vars->represent_env[i][j] != '\0')
		{
			if (vars->represent_env[i][j] == 'E')
			{
				vars->positions.dx = i;
				vars->positions.dy = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	valid_collectibles(int x, int y, t_vars *vars)
{
	int	found_collects;
	int	i;
	int	j;

	i = -1;
	found_collects = 0;
	while (vars->represent_env[++i] != NULL)
	{
		j = -1;
		while (vars->represent_env[i][++j] != '\0')
		{
			if (vars->represent_env[i][j] == 'C')
			{
				reset_visited(vars);
				vars->positions.dx = i;
				vars->positions.dy = j;
				if (backtracking(x, y, vars))
					found_collects++;
			}
		}
	}
	return (found_collects);
}

int	check_if_therese_way(int x, int y, t_vars *vars)
{
	int	found_exit;
	int	found_collects;

	found_exit = 0;
	found_collects = 0;
	find_exit_position(vars);
	if (backtracking(x, y, vars))
		found_exit = 1;
	found_collects = valid_collectibles(x, y, vars);
	return (found_exit && found_collects == vars->how_much_collect);
}
