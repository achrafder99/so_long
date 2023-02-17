/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:39:05 by adardour          #+#    #+#             */
/*   Updated: 2023/02/15 23:14:56 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_walls(char *path)
{
	int	number_of_line;
	int	check_lines;

	number_of_line = get_lines(path);
	check_lines = check_every_line(path, number_of_line);
	if (check_lines)
		return (1);
	return (0);
}
