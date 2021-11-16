/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:10:42 by tchalifo          #+#    #+#             */
/*   Updated: 2021/09/24 09:10:44 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_haystack;
	size_t	i_needle;

	i_haystack = 0;
	i_needle = 0;
	if (needle[i_needle] == '\0')
		return ((char *)&haystack[i_haystack]);
	while (haystack[i_haystack] != '\0' && i_haystack < len)
	{
		while (haystack[i_haystack] != '\0' && \
			haystack[i_haystack + i_needle] == needle[i_needle] && \
				(i_haystack + i_needle) < len)
		{
			if (needle[i_needle + 1] == '\0')
				return ((char *)&haystack[i_haystack]);
			i_needle++;
		}
		i_needle = 0;
		i_haystack++;
	}
	return (NULL);
}
