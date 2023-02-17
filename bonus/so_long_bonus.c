/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:09:40 by adardour          #+#    #+#             */
/*   Updated: 2023/02/15 22:09:56 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_variables(t_vars *vars, char *path)
{
	vars->represent_env = fill(path);
	vars->how_much_collect = get_number_of_fish(vars->represent_env);
	vars->player_x = get_position_x(vars->represent_env);
	vars->player_y = get_position_y(vars->represent_env);
	vars->path = ft_strdup(path);
	vars->visited = malloc(get_lines(vars->path) * sizeof(char *));
	vars->moves = 0;
}

void	init_mlx(t_vars *vars)
{
	int	width_screen;
	int	height_screen;

	vars->mlx = mlx_init();
	init_img(vars);
	width_screen = (get_column(vars->represent_env)) * 50;
	height_screen = get_lines(vars->path) * 50;
	vars->win = mlx_new_window(vars->mlx, width_screen, height_screen,
			"My window");
	mlx_hook(vars->win, 2, 0, key_event, vars);
	mlx_mouse_hook(vars->win, kill, vars);
}

void	start_mlx_loop(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, start_drawing_bonus, vars);
	mlx_hook(vars->win, 17, 0, exit_, 0);
	mlx_loop(vars->mlx);
}

void	play_game(int c, char **v)
{
	int		valid;
	int		valid_path;
	t_vars	vars;

	valid = check_file_ber(c, v[1]);
	if (valid)
	{
		init_variables(&vars, v[1]);
		if (check_symbols(vars.represent_env))
		{
			init_visited(&vars);
			valid_path = check_if_therese_way(vars.player_x, vars.player_y,
					&vars);
			if (valid_path)
			{
				init_mlx(&vars);
				start_mlx_loop(&vars);
			}
			else
				ft_putstr_fd("The map must be valild\n", 2);
		}
	}
	else
		ft_putstr_fd("The File is not in correct Format\n", 2);
}

int	main(int c, char **v)
{
	int		fd;

	fd = open(v[1], O_RDONLY);
	if (fd == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	else
		play_game(c, v);
	return (0);
}
