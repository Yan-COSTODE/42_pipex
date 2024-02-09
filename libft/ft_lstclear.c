/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:02:50 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/07 14:06:44 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!del || !lst || !*lst)
		return ;
	next = (*lst)->next;
	if (next)
		ft_lstclear(&next, del);
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
