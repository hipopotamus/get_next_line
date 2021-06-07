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

static char *buffer;

void get_buffer()
{	
	if(buffer == NULL)
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	else
	{
		char *temp_buffer;
		int size;

		size = ft_strlen(buffer);
		temp_buffer = malloc(sizeof(char) * (size + BUFFER_SIZE + 1));
		ft_strlcpy(temp_buffer, buffer, size + 1);
		buffer = malloc(sizeof(char) * (size + BUFFER_SIZE + 1));
		ft_strlcpy(buffer, temp_buffer, size + 1);
	}
}

int get_next_line(int fd, char **line)
{
	char *buffer_read;
	int size_line;
	int nl;

	nl = 0;
	buffer_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while(nl == 0)
	{
		get_buffer();
		read(fd, buffer_read, BUFFER_SIZE);
		printf("line = %s\n", buffer_read);
		ft_strlcat(buffer, buffer_read, ft_strlen(buffer) + BUFFER_SIZE + 1);
		nl = find_new(buffer);
	}
	size_line = find_new(buffer);
	*line = malloc(sizeof(char) * (size_line + 1));
	ft_strlcpy(*line, buffer, size_line);
	ft_strlcpy_del(buffer, &(buffer[size_line]), ft_strlen(buffer));

	return 0;
}
