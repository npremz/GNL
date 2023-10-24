/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:39:49 by npremont          #+#    #+#             */
/*   Updated: 2023/10/24 17:57:43 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alloc_buffer(char *buf, int i, char *src)
{
	char	*new_buf;
	int		size;
	int 	j;

	if (ft_has_newline(src) == 0)
		size = (i * BUFFER_SIZE) + 1;
	else
	{
		j = 0;
		while (src[j] && src[j] != '\n')
			++j;
		++j;
		size = ((i - 1) * BUFFER_SIZE) + j + 1;
	}
	new_buf = malloc(size * sizeof(char));
	if (!new_buf)
		return (NULL);
	ft_strlcpy(new_buf, buf, i * BUFFER_SIZE + 1);
	return (new_buf);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_size;
	size_t	src_size;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen((char *)src);
	j = dst_size;
	i = 0;
	if (dstsize == 0 || dstsize <= dst_size)
		return (src_size + dstsize);
	while (src[i] != '\0' && i < dstsize - dst_size - 1)
	{
		dst[j] = src[i];
		++i;
		++j;
	}
	dst[j] = '\0';
	return (dst_size + src_size);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
	{
		dst[i] = '\0';
		return (0);
	}
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_has_newline(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		++i;	
	}
	return (0);
}
