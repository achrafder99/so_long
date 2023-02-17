/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:18:39 by adardour          #+#    #+#             */
/*   Updated: 2023/02/15 23:08:06 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	get_position_y(char **world)
{
	int	column;
	int	i;
	int	j;

	column = 0;
	i = 0;
	while (world[i] != '\0')
	{
		j = 0;
		while (world[i][j] != '\0')
		{
			if (world[i][j] == 'P')
			{
				column = j;
				return (column);
			}
			j++;
		}
		i++;
	}
	return (0);
}
