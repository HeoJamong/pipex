/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <jheo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:31:19 by jheo              #+#    #+#             */
/*   Updated: 2024/07/08 22:48:10 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	all_free(char **ptr, size_t index)
{
	size_t	i;

	i = 0;
	while (i <= index)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static	size_t	word_count(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			cnt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cnt);
}

static	char	**make_split(char const *s, char c, size_t cnt, char **arr)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < cnt)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] != c && s[len] != '\0')
			len++;
		arr[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arr[i])
		{
			all_free(arr, i);
			return (NULL);
		}
		ft_memcpy(arr[i], s, len);
		arr[i++][len] = 0;
		s += len;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	cnt;
	char	**arr;

	if (!s)
		return (NULL);
	cnt = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!arr)
		return (0);
	if (!make_split(s, c, cnt, arr))
		return (NULL);
	return (arr);
}
