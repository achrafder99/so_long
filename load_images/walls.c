/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:13:22 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 17:07:16 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_walls_texture(t_vars *vars)
{
	vars->img.walls.img = mlx_xpm_file_to_image(vars->mlx, "texture/walls.xpm",
			&vars->img.walls.width, &vars->img.walls.height);
	if (vars->img.walls.img == NULL)
	{
		ft_putstr_fd("Error: could not load texture/walls.xpm\n", 2);
		exit(EXIT_FAILURE);
	}
}
