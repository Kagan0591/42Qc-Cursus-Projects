/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:56:38 by tchalifo          #+#    #+#             */
/*   Updated: 2021/09/20 13:56:39 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclenght;

	srclenght = ft_strlen(src);
	if (dstsize == 0)
		return (srclenght);
	while (*src && dstsize-- > 1)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (srclenght);
}
