/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_and_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:52:33 by adardour          #+#    #+#             */
/*   Updated: 2023/02/13 15:35:55 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_characters(char *line, t_vars *vars)
{
	int	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (line[j] == 'E')
			vars->exit++;
		else if (line[j] == 'P')
			vars->player++;
		else if (line[j] == 'C')
			vars->collectible++;
		j++;
	}
}

int	check_exit_and_player(char *path)
{
	t_vars	vars;
	char	*line;

	vars.fd = open(path, O_RDONLY, 777);
	vars.player = 0;
	vars.collectible = 0;
	vars.exit = 0;
	line = get_next_line(vars.fd);
	while (line != NULL)
	{
		check_characters(line, &vars);
		free(line);
		line = NULL;
		line = get_next_line(vars.fd);
	}
	free(line);
	line = NULL;
	return (vars.collectible > 0 && vars.player == 1 && vars.exit == 1);
}
