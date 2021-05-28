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
	char **line = malloc(sizeof(char*)*1);
	line[0] = malloc(sizeof(char)*100);
	char **line2 = malloc(sizeof(char*)*1);
	line2[0] = malloc(sizeof(char)*100);
	buffer = malloc(sizeof(char) * 100);
	int fd = open("./testtxt.txt", O_RDONLY);

	int a;
	get_next_line(fd, line);
	printf("----\n");
	get_next_line(fd, line2);
	printf("line = %s\n", line[0]);
	printf("line2 = %s\n", line2[0]);
	close(fd);
	return 0;
}
