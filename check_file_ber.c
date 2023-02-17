/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_ber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:32:41 by adardour          #+#    #+#             */
/*   Updated: 2023/02/16 21:42:36 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *extension)
{
	return (ft_strcmp(extension, "ber") == 0);
}

int	check_file_extension(char *filename)
{
	char	*extension;
	char	*dot_ptr;

	dot_ptr = ft_strrchr(filename, '.');
	if (dot_ptr == NULL)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	extension = dot_ptr + 1;
	if (!check_extension(extension))
		return (0);
	return (1);
}

void	show_errors(int number_error)
{
	if (number_error == 1)
	{
		ft_putstr_fd(DISPLAY_ERROR, 1);
		exit(EXIT_FAILURE);
	}
	else if (number_error == 3)
	{
		ft_putstr_fd(DISPLAY_ERROR3, 1);
		exit(EXIT_FAILURE);
	}
	else if (number_error == 4)
	{
		ft_putstr_fd(DISPLAY_ERROR4, 1);
		exit(EXIT_FAILURE);
	}
}

int	check_file_ber(int count, char *path)
{
	if (count != 2)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (!check_file_extension(path))
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (!check_walls(path))
		show_errors(3);
	if (!check_is_rectangular(path, get_lines(path)))
		show_errors(4);
	if (!check_exit_and_player(path))
		show_errors(1);
	return (1);
}
