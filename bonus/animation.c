/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:40:41 by adardour          #+#    #+#             */
/*   Updated: 2023/02/17 23:29:50 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	update_sign(int sign)
{
	if (sign == 0)
		sign = 1;
	return (sign);
}

int	update_represent_env(t_vars *vars, int k, int o, int sign)
{
	if (vars->represent_env[k][o] == 'N')
	{
		if (vars->represent_env[k][o - sign] == '1' || vars->represent_env[k][o - sign] == 'C' || vars->represent_env[k][o - sign] == 'E'|| vars->represent_env[k][o - sign] == 'C')
			sign = -sign;
		if (vars->represent_env[k][o - sign] != '1' && vars->represent_env[k][o
			- sign] != 'C' && vars->represent_env[k][o - sign] != 'E'
			&& (vars->represent_env[k][o - sign] != 'P'))
		{
			vars->represent_env[k][o - sign] = 'N';
			vars->represent_env[k][o] = '0';
		}
	}
	return (sign);
}

int	animation(void *params)
{
	t_vars		*vars;
	int			k;
	int			o;
	static int	i;
	static int	sign;

	sign = update_sign(sign);
	vars = (t_vars *)params;
	k = -1;
	if (i == 200)
	{
		while (vars->represent_env[++k] != NULL)
		{
			o = -1;
			while (vars->represent_env[k][++o] != '\0')
				sign = update_represent_env(vars, k, o, sign);
		}
		i = 0;
	}
	i++;
	return (1);
}
