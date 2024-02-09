/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:19:01 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/06 17:58:52 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	int				nb;

	if (nmemb * size > INT32_MAX || (nmemb > UINT16_MAX && size > INT16_MAX))
		return (NULL);
	nb = nmemb * size;
	ptr = (unsigned char *) malloc(nb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nb);
	return (ptr);
}
