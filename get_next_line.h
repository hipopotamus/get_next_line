#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


# ifndef BUFFER_SIZE
# define BUFFER_SIZE 6
# endif

char* buffer;

int	get_next_line(int fd, char **line);
int	find_new(char *s);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t ft_strlcpy_del(char *dst, const char *src, size_t dstsize);

#endif
