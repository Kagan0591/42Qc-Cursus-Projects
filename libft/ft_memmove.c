/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:56:00 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/22 10:06:22 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	if (!dst && !src)
		return (0);
	if (ptr_dst > ptr_src)
	{
		while (len-- > 0)
			if (ptr_dst[len] != ptr_src[len])
				ptr_dst[len] = ptr_src[len];
	}
	else
	{
		while (len-- > 0)
		{
			if (*ptr_dst != *ptr_src)
				*ptr_dst = *ptr_src;
			ptr_dst++;
			ptr_src++;
		}
	}
	return (dst);
}
