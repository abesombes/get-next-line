/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 00:15:53 by abesombe          #+#    #+#             */
/*   Updated: 2020/12/06 00:16:01 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_create_line_fill_tmp(char **tmp, char **line, char *buf, int i)
{
	char *str;

	free(buf);
	*line = ft_strndup(*tmp, i);
	str = *tmp;
	*tmp = ft_strndup(str + i + 1, ft_strlen(str) - i - 1);
	free(str);
	return (1);
}

int	ft_merge_tmp_buf_update_tmp(char **tmp, char **line, char *buf, int i)
{
	char *str;

	str = ft_strndup(buf, i);
	*line = ft_strjoin(*tmp, str);
	free(*tmp);
	free(str);
	*tmp = ft_strndup(buf + i + 1, ft_strlen(buf) - i - 1);
	free(buf);
	return (1);
}

int	ft_set_all(char **line, char **tmp, char *buf)
{
	free(buf);
	if (*tmp)
	{
		*line = ft_strndup(*tmp, ft_strlen(*tmp));
		free(*tmp);
	}
	else
		*line = ft_strndup("", 0);
	*tmp = 0;
	return (0);
}

int	ft_free_tmp(char **tmp)
{
	free(*tmp);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	int			ret;
	int			i;
	char		*buf;
	static char *tmp[65536];

	if (fd < 0 || fd > 65536)
		return (-1);
	if (BS < 1 || !line || !(buf = malloc(sizeof(char) * (BS + 1))))
		return (ft_free_tmp(&tmp[fd]));
	if ((i = ft_strchr_index(tmp[fd], '\n')) >= 0)
		return (ft_create_line_fill_tmp(&tmp[fd], line, buf, i));
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ret > 0)
		{
			if ((i = ft_strchr_index(buf, '\n')) >= 0)
				return (ft_merge_tmp_buf_update_tmp(&tmp[fd], line, buf, i));
			else
				tmp[fd] = ft_strjoin(tmp[fd], buf);
		}
	}
	if (ret < 0)
		return (ft_free_tmp(&tmp[fd]));
	return (ft_set_all(line, &tmp[fd], buf));
}
