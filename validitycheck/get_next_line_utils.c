/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gna <gna@student.42Seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 23:56:43 by gna               #+#    #+#             */
/*   Updated: 2020/04/20 17:57:01 by gna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"

char	*ft_strcpy(char *dest, const char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int	i;
	int	len;
	char	*new_s;

	i = 0;
	len = 0;
	while (s[len] != '\0')
		len++;
	if (!(new_s = (char *)malloc(sizeof(char) * (len + 1))))
		return ((char *)(0));
	while (s[i] != '\0')
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		end;
	char		*sub_s;
	unsigned int	s_len;

	i = 0;
	if (s == 0)
		return (NULL);
	s_len = 0;
	while (s[s_len] != '\0')
		s_len++;
	if (start > s_len)
		return (ft_strdup(""));
	if (!(sub_s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	end = start + len;
	while (start < end && s[start] != '\0')
	{
		sub_s[i] = s[start];
		i++;
		start++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

char	*ft_strjoin(char const *s1, const char *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	char		*new_s;

	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;
	if (!(new_s = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return ((char *)(0));
	ft_strcpy(new_s, s1);
	ft_strcat(new_s, s2);
	return (new_s);
}
