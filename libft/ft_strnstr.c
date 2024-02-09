/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:54:28 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/06 18:40:50 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
		return ((char *) big);
	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (big[i] && i + j < len)
	{
		j = 0;
		if (little[j] == big[i])
		{
			while (little[j] == big[i + j] && big[i + j] && i + j < len)
				j++;
			if ((j == len || j == ft_strlen(little))
				&& ft_strlen(little) <= len)
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
