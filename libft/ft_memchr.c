/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:25:25 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/01 14:26:47 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	ch;

	ch = (unsigned char) c;
	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ch)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
