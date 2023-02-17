/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:44:19 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 16:36:32 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_symbols(char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
		{
			if (env[i][j] == 'N')
				j++;
			if ((env[i][j] != '0' && env[i][j] != '1' && env[i][j] != 'C'
					&& env[i][j] != 'P' && env[i][j] != 'E'
					&& env[i][j] != '\n'))
			{
				ft_putstr_fd("some symbols not valid\n", 2);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (1);
}
