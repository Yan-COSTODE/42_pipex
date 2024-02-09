/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:47:03 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/03 23:59:04 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			*ptr;
	unsigned char	*ptr_last;

	ptr = (size_t *) s;
	while (n >= sizeof(size_t))
	{
		*ptr = 0;
		++ptr;
		n -= sizeof(size_t);
	}
	ptr_last = (unsigned char *) ptr;
	++n;
	while (--n)
	{
		*ptr_last = 0;
		++ptr_last;
	}
}
