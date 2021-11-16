/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:54:54 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/22 10:33:34 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_lenght;

	s_lenght = ft_strlen(s);
	while (*s)
		s++;
	if (*s + 1 == '\0')
		return ((char *)s + 1);
	while (s_lenght-- >= 0)
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
