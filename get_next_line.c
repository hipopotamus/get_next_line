/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:04:48 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/28 13:37:16 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	while(find_new(buffer) == 0)
	{
		read(fd, buffer, BUFFER_SIZE);
	}
	*line = buffer;
	return 0;
}
