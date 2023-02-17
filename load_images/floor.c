/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:10:29 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 17:07:21 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_floor_texture(t_vars *vars)
{
	vars->img.floor.img = mlx_xpm_file_to_image(vars->mlx, "texture/floor.xpm",
			&vars->img.floor.width, &vars->img.floor.height);
	if (vars->img.floor.img == NULL)
	{
		ft_putstr_fd("Error: could not load texture/floor.xpm\n", 2);
		exit(EXIT_FAILURE);
	}
}
