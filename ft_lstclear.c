/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtar <acourtar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:46:17 by acourtar          #+#    #+#             */
/*   Updated: 2022/10/26 14:21:17 by acourtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// free()s the content of the nodes (del() handles that) 
// as well as the node itself. lst->next should NOT be freed by del().
// *lst becomes NULL at the end, no need to assign the NULL again at the end.
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	next = (*lst);
	while ((next) != NULL)
	{
		next = (*lst)->next;
		del((**lst).content);
		free(*lst);
		*lst = next;
	}
}
