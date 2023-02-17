/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_position_is_valid.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:45:07 by adardour          #+#    #+#             */
/*   Updated: 2023/02/08 21:47:06 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_if_position_is_valid(char **world)
{
	int	x;
	int	y;
	int	walls_count;

	walls_count = 0;
	x = get_position_x(world);
	y = get_position_y(world);
	if (world[x - 1][y] == '1')
		walls_count++;
	if (world[x][y - 1] == '1')
		walls_count++;
	if (world[x][y + 1] == '1')
		walls_count++;
	if (world[x + 1][y] == '1')
		walls_count++;
	return (walls_count);
}
