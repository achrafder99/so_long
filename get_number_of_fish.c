/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_of_fish.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:24:22 by adardour          #+#    #+#             */
/*   Updated: 2023/02/08 22:47:12 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_number_of_fish(char **world)
{
	int	fish;
	int	i;
	int	j;

	fish = 0;
	i = 0;
	while (world[i] != NULL)
	{
		j = 0;
		while (world[i][j] != '\0')
		{
			if (world[i][j] == 'C')
				fish++;
			j++;
		}
		i++;
	}
	return (fish);
}
