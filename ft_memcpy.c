/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheo <jheo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:08:54 by jheo              #+#    #+#             */
/*   Updated: 2024/07/09 16:29:06 by jheo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*target;
	unsigned char		*source;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	target = (unsigned char *) dest;
	source = (unsigned char *) src;
	while (i < n)
	{
		target[i] = source[i];
		i++;
	}
	return ((void *)target);
}
