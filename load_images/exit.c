/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:12:38 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 17:07:27 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_exit_texture(t_vars *vars)
{
	vars->img.exit_close.img = mlx_xpm_file_to_image(vars->mlx,
			"texture/exit.xpm", &vars->img.exit_close.width,
			&vars->img.exit_close.height);
	if (vars->img.exit_close.img == NULL)
	{
		ft_putstr_fd("Error: could not load texture/exit.xpm\n", 2);
		exit(EXIT_FAILURE);
	}
}
