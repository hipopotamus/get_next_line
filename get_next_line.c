/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:04:48 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/28 16:14:13 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static ssize_t	read_in_buffer(int fd, t_gnl_object *object)
{
	ssize_t readn;

	readn = read(fd, object->buffer, BUFFER_SIZE);
	if (readn == -1 || readn == 0)
		return (readn);
	object->location = 0;
	object->end = readn - 1;
	object->possible_copy = 1;
	return (readn);
}

static int		expand_line(char **line)
{
	char	*new_line;
	size_t	line_size;
	line_size = ft_strlen(*line);
	if (!(new_line = calloc(line_size + (2 * BUFFER_SIZE), sizeof(char))))
		return (-1);
	ft_memccpy(new_line, *line, '\0', line_size + 1);
	free(*line);
	*line = new_line;
	return (1);
}

static int		get_first_line(char **line)
{
	*line = NULL;
	if (!(*line = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (-1);
	return (1);
}

static int		copy_buffer_to_line(char **line, t_gnl_object *object)
{
	size_t	line_idx;
	char	ch;

	line_idx = ft_strlen(*line);
	while (object->location <= object->end)
	{
		ch = (object->buffer)[object->location];
		if (ch == '\n')
		{
			if (object->location == object->end)
				object->possible_copy = 0;
			else
				object->location++;
			return (0);
		}
		(*line)[line_idx] = ch;
		line_idx++;
		object->location++;
	}
	object->possible_copy = 0;
	return (1);
}


int			get_next_line(int fd, char **line)
{
	static t_gnl_object	object[FD_NUMBER];
	ssize_t				readn;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (get_first_line(line) == -1)
		return (-1);
	if (object[fd].possible_copy == 0)
	{
		readn = read_in_buffer(fd, &object[fd]);
		if (readn == -1 || readn == 0)
			return (readn);
	}
	while (copy_buffer_to_line(line, &object[fd]) == 1)
	{
		readn = read_in_buffer(fd, &object[fd]);
		if (readn == -1 || readn == 0)
			return (readn);
		if (expand_line(line) == -1)
			return (-1);
	}
	return (1);
}
