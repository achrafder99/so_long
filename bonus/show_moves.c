/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:05:07 by adardour          #+#    #+#             */
/*   Updated: 2023/02/17 23:32:05 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	show_moves(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0xFFFFFF, "Number of moves :");
	mlx_string_put(vars->mlx, vars->win, 190, 10, 0xFFFFFF, ft_itoa(vars->moves));
	animation(vars);
}
