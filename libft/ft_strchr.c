/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:37:24 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/07 11:02:56 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;
	unsigned char	st;

	str = (unsigned char *) s;
	st = (unsigned char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == st)
			return ((char *)&str[i]);
		i++;
	}
	if (st == 0)
		return ((char *)&str[i]);
	return (NULL);
}
