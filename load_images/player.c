/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:11:48 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 17:07:19 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_player_texture(t_vars *vars)
{
	vars->img.player.img = mlx_xpm_file_to_image(vars->mlx,
			"texture/player2.xpm", &vars->img.player.width,
			&vars->img.player.height);
	if (vars->img.player.img == NULL)
	{
		ft_putstr_fd("Error: could not load texture/player2.xpm\n", 2);
		exit(EXIT_FAILURE);
	}
}
