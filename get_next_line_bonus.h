/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:39:46 by npremont          #+#    #+#             */
/*   Updated: 2023/10/27 13:49:23 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* INCLUDES */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

/* FUNCTIONS */

char	*ft_strjoin(char *prefix, char *suffix, int has_fail);
void	*ft_calloc(size_t count, size_t size);
int		ft_has_newline(char *str);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
char	*get_next_line(int fd);
void	ft_free(char **ptr, int flag, char **buff);
