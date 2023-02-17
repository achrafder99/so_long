/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:14:45 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 17:07:24 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_enemy_texture(t_vars *vars)
{
	vars->img.enemy.img = mlx_xpm_file_to_image(vars->mlx, "texture/enemy.xpm",
			&vars->img.enemy.width, &vars->img.enemy.height);
	if (vars->img.enemy.img == NULL)
	{
		ft_putstr_fd("Error: could not load texture/enemy.xpm\n", 2);
		exit(EXIT_FAILURE);
	}
}
