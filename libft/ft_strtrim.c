/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:46:07 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/03 10:50:33 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_bool	ft_isinset(const char c, const char *set)
{
	int	i;

	if (!set)
		return (FALSE);
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		front;
	int		back;

	if (!s1)
		return (NULL);
	front = ft_strlen(s1) - 1;
	back = 0;
	while (ft_isinset(s1[front], set) || ft_isinset(s1[back], set))
	{
		if (ft_isinset(s1[front], set))
			front--;
		if (ft_isinset(s1[back], set))
			back++;
	}
	s = ft_substr(s1, back, front - back + 1);
	if (!s)
		return (NULL);
	return (s);
}
