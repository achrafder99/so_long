/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:07:47 by adardour          #+#    #+#             */
/*   Updated: 2023/02/17 23:22:10 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_collectible_texture(t_vars *vars)
{
	vars->img.collect.img = mlx_xpm_file_to_image(vars->mlx,"texture/Collectible.xpm", &vars->img.collect.width,&vars->img.collect.height);
	if (vars->img.collect.img == NULL)
	{
		ft_putstr_fd("Error: could not load texture/Collectible.xpm\n", 2);
		exit(EXIT_FAILURE);
	}
}
