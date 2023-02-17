/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_rectangular.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:38:27 by adardour          #+#    #+#             */
/*   Updated: 2023/02/15 22:50:21 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	open_and_read_file(char *path, int number_of_lines, size_t *line_len)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY, 777);
	if (fd == -1)
		return (-1);
	i = 0;
	while (i < number_of_lines)
	{
		line = get_next_line(fd);
		if (i == 0)
			*line_len = ft_strlen(line);
		else if (ft_strlen(line) != *line_len)
		{
			if (i == number_of_lines - 1 && ft_strlen(line) == *line_len - 1)
				break ;
			free(line);
			return (0);
		}
		free(line);
		i++;
	}
	free(line);
	return (1);
}

int	check_is_rectangular(char *path, int number_of_lines)
{
	size_t	line_len;
	int		result;

	result = open_and_read_file(path, number_of_lines, &line_len);
	if (result == -1)
		return (-1);
	return (result);
}
