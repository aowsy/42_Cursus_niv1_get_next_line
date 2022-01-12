/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelforg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:15:36 by mdelforg          #+#    #+#             */
/*   Updated: 2022/01/07 13:11:40 by mdelforg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s || !*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_calloc(size_t size)
{
	size_t	i;
	char	*tab;

	tab = malloc(size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = '\0';
		i++;
	}
	return (&tab[0]);
}

char	*ft_strjoin(char const *s1, char const *s2, int i)
{
	char	*str;
	int		j;

	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free((char *)s1);
	return (&str[0]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		str = malloc(sizeof(*str) * (ft_strlen(s) + 1));
	else
		str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while ((i + start < ft_strlen(s)) && (i < len))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	if (start)
		free((char *)s);
	return (&str[0]);
}
