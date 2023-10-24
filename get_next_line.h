/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:39:46 by npremont          #+#    #+#             */
/*   Updated: 2023/10/24 18:51:40 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* INCLUDES */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

/* FUNCTIONS */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_size(char *str);
int		ft_has_newline(char *str);
char	*alloc_buffer(char *buf, int i, char *src);
