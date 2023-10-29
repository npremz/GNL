/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:39:46 by npremont          #+#    #+#             */
/*   Updated: 2023/10/29 16:15:28 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* INCLUDES */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 19
# endif

/* FUNCTIONS */

char	*ft_strjoin(char *prefix, char *suffix, int has_fail);
void	*ft_calloc(size_t count, size_t size);
int		ft_has_newline(char *str);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
void	ft_free(char **ptr, int flag, char **buff);

#endif
