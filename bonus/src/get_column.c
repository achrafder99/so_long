/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:30:49 by adardour          #+#    #+#             */
/*   Updated: 2023/02/15 23:02:36 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	get_column(char **env)
{
	int	i;
	int	j;
	int	column;

	column = 0;
	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
			j++;
		i++;
		column = j;
	}
	return (column);
}
