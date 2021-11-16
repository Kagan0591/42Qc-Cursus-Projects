/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:33:55 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/20 16:30:37 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_node;

	if (alst || new)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			last_node = ft_lstlast(*alst);
			last_node->next = new;
		}
	}
}
