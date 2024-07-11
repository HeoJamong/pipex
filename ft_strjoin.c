/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <jheo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:10:45 by jheo              #+#    #+#             */
/*   Updated: 2024/07/11 16:53:23 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*arr;

	if (!s1 || !s2)
		return (0);
	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	arr = (char *)malloc((s1_len + s2_len + 1) * (sizeof(char)));
	if (arr == 0)
		return (0);
	while (++i < s1_len)
		arr[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		arr[s1_len + i] = s2[i];
	arr[s1_len + i] = '\0';
	return (arr);
}
