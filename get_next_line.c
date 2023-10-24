/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:39:43 by npremont          #+#    #+#             */
/*   Updated: 2023/10/24 18:57:49 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_endline(char *str)
{
	char	*res;
	int		i;

	res = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!res)
		return (0);
	i = 0;
	while (str[i] != '\n')
	{
		res[i] = str[i];
		++i;
	}
	res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

static char	*ft_get_startline(char *str)
{
	char	*res;
	int		i;

	res = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!res)
		return (0);
	while (*str != '\n')
		++str;
	++str;
	i = 0;
	while (str[i] != '\0')
	{
		res[i] = str[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

static char	*ft_handle_endline(char *res, char *buf, int size, int r_bytes)
{
	char	*end_line;
	char	*start_line;

	end_line = ft_get_endline(buf);
	start_line = NULL;
	ft_strlcat(res, end_line, size);
	if ((int)ft_strlen(end_line) == r_bytes)
		return (NULL);
	start_line = ft_get_startline(buf);
	free(end_line);
	return (start_line);
}

char	*ft_handle_lastline(char **stock, int *index)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!res)
		return (free(*stock), NULL);
	*index += 1;
	ft_strlcat(res, *stock, BUFFER_SIZE + 1);
	*stock = NULL;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		buf[BUFFER_SIZE + 1];
	char		*res;
	int			r_bytes;
	int			i;

	i = 0;
	res = NULL;
	buf[0] = '\0';
	if (stock)
		res = ft_handle_lastline(&stock, &i);
	while (ft_has_newline(buf) == 0 && stock == NULL)
	{
		r_bytes = read(fd, buf, BUFFER_SIZE);
		buf[r_bytes] = '\0';
		if (r_bytes != 0)
		{
			res = alloc_buffer(res, ++i, buf);
			if (ft_has_newline(buf) == 0)
				ft_strlcat(res, buf, BUFFER_SIZE * i + 1);
			else
				stock = ft_handle_endline(res, buf, BUFFER_SIZE * i + 1, r_bytes);
		}
		else
			break ;
	}
	return (res);
}

int	main(int ac, char *av[])
{
	int	fd;
	char *path;

	path = av[ac - 1];
	fd = open(path, O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	close(fd);
	return (0);
}
