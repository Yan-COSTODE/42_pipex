/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:48:23 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/07 11:05:41 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				pos;
	unsigned char	*str;
	unsigned char	st;

	str = (unsigned char *) s;
	st = (unsigned char) c;
	i = 0;
	pos = -1;
	while (str[i])
	{
		if (str[i] == st)
			pos = i;
		i++;
	}
	if (st == 0)
		pos = ft_strlen(s);
	if (pos < 0)
		return (NULL);
	else
		return ((char *)&str[pos]);
}
