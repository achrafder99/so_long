/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:17:06 by adardour          #+#    #+#             */
/*   Updated: 2023/02/12 18:39:08 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_position_x(char **world)
{
	int	line;
	int	i;
	int	j;

	line = 0;
	i = 0;
	while (world[i] != '\0')
	{
		j = 0;
		while (world[i][j] != '\0')
		{
			if (world[i][j] == 'P')
			{
				line = i;
				return (line);
			}
			j++;
		}
		i++;
	}
	return (0);
}
