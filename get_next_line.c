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

static int real_fd;

int get_next_line(int fd, char **line)
{
	char *buffer_read;
	buffer_read = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while(find_new(buffer) == 0)
	{
		read(fd, buffer_read, BUFFER_SIZE);
		ft_strlcat(buffer, buffer_read, ft_strlen(buffer) + BUFFER_SIZE + 1);
	}
	ft_strlcpy(*line, buffer, find_new(buffer));
	//printf("newline = %s\n", &(buffer[find_new(buffer)]));
	ft_strlcpy_del(buffer, &(buffer[find_new(buffer)]), ft_strlen(buffer));

	return 0;
}
