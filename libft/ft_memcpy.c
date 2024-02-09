/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:52:05 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/04 00:03:50 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	cdest = (unsigned char *) dest;
	csrc = (const unsigned char *) src;
	i = 0;
	while (n - i)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
