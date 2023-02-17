/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:29:16 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 16:57:21 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_img(t_vars *vars)
{
	load_collectible_texture(vars);
	load_floor_texture(vars);
	load_player_texture(vars);
	load_exit_texture(vars);
	load_walls_texture(vars);
	load_enemy_texture(vars);
}
