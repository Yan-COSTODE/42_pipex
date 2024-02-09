/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:01:52 by ycostode          #+#    #+#             */
/*   Updated: 2023/10/31 12:04:47 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		n;
	t_list	*current;

	if (!lst)
		return (0);
	n = 1;
	current = lst;
	while (current->next)
	{
		current = current->next;
		n++;
	}
	return (n);
}
