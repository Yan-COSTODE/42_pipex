/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:22:56 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/06 17:22:15 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				length;
	int				sign;
	char			*num;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	nb = n * sign;
	length = ft_size(n);
	num = (char *) ft_calloc(length + 1, sizeof(char));
	if (!num)
		return (NULL);
	num[length--] = '\0';
	while (length >= 0)
	{
		num[length--] = nb % 10 + '0';
		nb /= 10;
	}
	if (sign == -1)
		num[0] = '-';
	return (num);
}
