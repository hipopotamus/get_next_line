/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:32:14 by sungwopa          #+#    #+#             */
/*   Updated: 2021/05/28 16:00:58 by sungwopa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int find_new(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == '\n')
			return i + 1;
		i++;
	}
	return 0;
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len_dst;
	size_t len_src;
	size_t i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if(dstsize <= len_dst)
		return (dstsize + len_src);
	while (src[i] != '\0' && i < dstsize - len_dst -1)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	while(src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

size_t ft_strlcpy_del(char *dst, const char *src, size_t dstsize)
{
	ft_strlcpy(dst, src, dstsize);
	while(dst[dstsize] != '\0')
	{
		dst[dstsize] = '\0';
		dstsize++;
	}
	return dstsize;
}
