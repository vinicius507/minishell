/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:56:03 by vgoncalv          #+#    #+#             */
/*   Updated: 2021/05/29 16:56:03 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reassign(char **save, char *dest)
{
	if (*save != NULL)
	{
		free(*save);
		*save = dest;
	}
}

static int	linelen(char *line)
{
	size_t	len;

	len = 0;
	while (line[len])
	{
		if (line[len] == '\n')
			break ;
		len++;
	}
	return (len);
}

static t_gnlstatus	get_line(char **save, char **line)
{
	size_t	size;
	char	*temp;

	size = linelen(*save);
	if ((*save)[size] == '\0')
	{
		*line = ft_strdup(*save);
		reassign(save, NULL);
		if (*line == NULL)
			return (GNL_ERROR);
		return (END_OF_FILE);
	}
	*line = ft_substr(*save, 0, size);
	temp = ft_strdup((*save) + size + 1);
	if (temp == NULL || *line == NULL)
		return (GNL_ERROR);
	reassign(save, temp);
	return (NEWLINE);
}

static t_gnlstatus	output(char **save, char **line, ssize_t size_read)
{
	if (size_read == -1)
	{
		reassign(save, NULL);
		return (GNL_ERROR);
	}
	else if (size_read == 0 && *save == NULL)
	{
		*line = ft_strdup("");
		return (END_OF_FILE);
	}
	return (get_line(save, line));
}

int	get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	ssize_t		size_read;
	char		*buffer;
	char		*temp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (GNL_ERROR);
	size_read = read(fd, buffer, BUFFER_SIZE);
	while (size_read > 0)
	{
		buffer[size_read] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(save[fd], buffer);
			reassign(&(save[fd]), temp);
		}
		if (ft_strchr(save[fd], '\n'))
			break ;
		size_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (output(&(save[fd]), line, size_read));
}
