/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:42:25 by ycostode          #+#    #+#             */
/*   Updated: 2023/12/12 17:51:29 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freesplit(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (NULL);
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

static int	ft_strcount(const char *str, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1])
			n++;
		else if (i == 0 && str[i] != c)
			n++;
		i++;
	}
	return (n + 1);
}

static char	*ft_strtruncate(const char *s, int start, int index)
{
	char	*str;

	str = ft_substr(s, start, index - start + 1);
	if (!str)
		return (NULL);
	return (str);
}

static void	ft_init(int	*i, int *j, int	*start)
{
	*i = 0;
	*j = 0;
	*start = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		index[2];
	int		start;

	ft_init(&index[0], &index[1], &start);
	if (!s)
		return (NULL);
	str = (char **)ft_calloc(ft_strcount(s, c), sizeof(char *));
	if (!str)
		return (NULL);
	while (s[index[0]])
	{
		if (s[index[0]] == c && index[0] != 0 && s[index[0] - 1] != c)
			str[index[1]++] = ft_strtruncate(s, start, index[0] - 1);
		else if (!s[index[0] + 1] && s[index[0]] != c)
			str[index[1]++] = ft_strtruncate(s, start, index[0]);
		if (s[index[0]] == c && s[index[0] + 1] != c)
			start = index[0] + 1;
		else if (index[0] == 0 && s[index[0]] != c)
			start = index[0];
		if (index[1] != 0 && str[index[1] - 1] == NULL)
			return (ft_freesplit(str));
		++index[0];
	}
	return (str);
}
