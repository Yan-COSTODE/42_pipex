/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:07:46 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/04 00:04:21 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;

	if (!dest && !src)
		return (NULL);
	cdest = (unsigned char *) dest;
	csrc = (const unsigned char *) src;
	if (src < dest)
	{
		cdest = cdest + n - 1;
		csrc = csrc + n - 1;
		while (n--)
			*cdest-- = *csrc--;
	}
	else if (src >= dest)
	{
		while (n--)
			*cdest++ = *csrc++;
	}
	return (dest);
}
