/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visited.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:41:21 by adardour          #+#    #+#             */
/*   Updated: 2023/02/14 16:47:05 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_visited(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < get_lines(vars->path))
	{
		vars->visited[i] = malloc(get_column(vars->represent_env)
				* sizeof(char));
		ft_memset(vars->visited[i], '0', get_column(vars->represent_env)
			* sizeof(char));
		i++;
	}
}
