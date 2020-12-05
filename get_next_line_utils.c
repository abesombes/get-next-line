/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:14:05 by abesombe          #+#    #+#             */
/*   Updated: 2020/12/05 00:56:22 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strchr_index(const char *s, int c)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s == c)
			return (i);
		s++;
		i++;
	}
	if (*s == c)
		return (i);
	return (-1);
}

char	*ft_strndup(const char *s, int n)
{
	char	*dup;
	int		i;

	i = -1;
	if (!s || !(dup = (char *)(malloc(sizeof(char) * (ft_strlen(s) + 1)))))
		return (NULL);
	while (s[++i] && i < n)
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*jstr;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	size_s1 = (s1 ? ft_strlen(s1) : 0);
	size_s2 = (s2 ? ft_strlen(s2) : 0);
	if (!(jstr = (char *)malloc(size_s1 + size_s2 + 1)))
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i])
		{
			jstr[i] = s1[i];
			i++;
		}
	j = 0;
	if (s2)
		while (s2[j])
			jstr[i++] = s2[j++];
	jstr[i] = '\0';
	return (jstr);
}
