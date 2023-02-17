/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:37:01 by adardour          #+#    #+#             */
/*   Updated: 2023/02/13 15:44:34 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*fill_line(char *line)
{
	int		j;
	char	*env_line;

	env_line = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (env_line == NULL)
		return (NULL);
	j = 0;
	while (line[j] != '\0')
	{
		env_line[j] = line[j];
		j++;
	}
	env_line[j] = '\0';
	return (env_line);
}

char	**fill(char *path)
{
	int		fd;
	int		i;
	int		lines;
	char	*line;
	char	**env;

	lines = get_lines(path);
	env = (char **)malloc(sizeof(char *) * (lines) + 1);
	i = 0;
	fd = open(path, O_RDONLY, 777);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		env[i] = fill_line(line);
		if (env[i] == NULL)
			return (NULL);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	env[i] = NULL;
	free(line);
	return (env);
}
