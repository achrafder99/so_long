/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:58:07 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 16:56:54 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	exit_game(int keycode)
{
	if (keycode == 53)
	{
		exit(EXIT_FAILURE);
	}
}

int	key_event(int keycode, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	exit_game(keycode);
	if (keycode == 13)
		up(vars);
	else if (keycode == 1)
		down(vars);
	else if (keycode == 2)
		right(vars);
	else if (keycode == 0)
		left(vars);
	return (0);
}
