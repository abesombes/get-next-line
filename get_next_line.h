/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:09:47 by abesombe          #+#    #+#             */
/*   Updated: 2020/12/06 00:11:39 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
int		ft_strchr_index(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(char const *s, int n);

#endif

#ifndef BS
# define BS BUFFER_SIZE
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
