/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:43:22 by adardour          #+#    #+#             */
/*   Updated: 2023/02/15 23:01:41 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	get_lines(char *path)
{
	char	*line;
	int		lines;
	int		fd;

	lines = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	close(fd);
	return (lines);
}
