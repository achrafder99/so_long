/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_every_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:45:07 by adardour          #+#    #+#             */
/*   Updated: 2023/02/14 17:55:42 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_line(char *line, int len)
{
	int	j;

	j = 0;
	while (j < len && line[j] != '\n')
	{
		if (line[j] != '1')
			return (0);
		j++;
	}
	free(line);
	line = NULL;
	return (1);
}

int	check_remaining_lines(char *line, int len, int i, int lines)
{
	int	j;

	j = 0;
	if (i != lines - 1)
	{
		if (line[0] != '1' || line[len - 2] != '1')
			return (0);
	}
	else
	{
		while (line[j] != '\0')
		{
			if (line[j] != '1')
				return (0);
			j++;
		}
	}
	free(line);
	line = NULL;
	return (1);
}

int	check_line(char *line, int len, int i, int lines)
{
	if (i == 0)
		return (check_first_line(line, len));
	else
		return (check_remaining_lines(line, len, i, lines));
}

int	check_file(int lines, int fd)
{
	int		i;
	char	*line;
	int		len;

	i = 0;
	line = get_next_line(fd);
	if (lines < 3)
		return (0);
	while (i < lines)
	{
		len = ft_strlen(line);
		if (!check_line(line, len, i, lines))
		{
			free(line);
			line = NULL;
			close(fd);
			return (0);
		}
		line = get_next_line(fd);
		i++;
	}
	free(line);
	line = NULL;
	close(fd);
	return (1);
}

int	check_every_line(char *path, int lines)
{
	int	result;
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	result = 0;
	result = check_file(lines, fd);
	if (result == 0)
		return (0);
	return (1);
}
