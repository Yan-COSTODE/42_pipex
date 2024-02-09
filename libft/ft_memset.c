/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:37:12 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/03 23:58:49 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(int c)
{
	size_t			t_size;
	unsigned char	*ptr;
	int				i;

	i = sizeof(size_t);
	ptr = (unsigned char *) &t_size;
	while (--i >= 0)
		ptr[i] = c;
	return (t_size);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr_last;
	size_t			*ptr;
	size_t			value;

	value = ft_size(c);
	ptr = (size_t *) s;
	while (n >= sizeof(size_t))
	{
		*ptr = value;
		++ptr;
		n -= sizeof(size_t);
	}
	ptr_last = (unsigned char *) ptr;
	++n;
	while (--n)
	{
		*ptr_last = c;
		++ptr_last;
	}
	return (s);
}
