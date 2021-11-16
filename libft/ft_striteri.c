/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:10:55 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/19 09:10:57 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i_s;

	i_s = 0;
	if (s)
	{
		while (s[i_s])
		{
			(*f)(i_s, &s[i_s]);
			i_s++;
		}
	}
}
