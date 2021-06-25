/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:08:53 by sungwopa          #+#    #+#             */
/*   Updated: 2021/06/10 16:13:05 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

# ifndef FD_NUMBER
#  define FD_NUMBER 1024
# endif

typedef struct	s_gnl_object
{
	int			possible_copy;
	char		buffer[BUFFER_SIZE];
	size_t		location;
	size_t		end;
}				t_gnl_object;

int				get_next_line(int fd, char **line);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
size_t			ft_strlen(const char *s);

#endif
