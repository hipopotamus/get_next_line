/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:17:11 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/28 15:04:48 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	char *line = NULL;
	char *line2 = NULL;
	char *line3 = NULL;
	char *line4 = NULL;
	int fd = open("./testtxt.txt", O_RDONLY);

	get_next_line(fd, &line);
	get_next_line(fd, &line2);
	get_next_line(fd, &line3);
	get_next_line(fd, &line4);
	printf("line = %s\n", line);
	printf("line2 = %s\n", line2);
	printf("line3 = %s\n", line3);
	printf("line4 = %s\n", line4);
	close(fd);
	return 0;
}
