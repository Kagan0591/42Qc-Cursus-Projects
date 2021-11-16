/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:10:05 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/19 13:33:07 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i_s1;

	i_s1 = ft_strlen(s1) + 1;
	s2 = malloc(sizeof(*s2) * i_s1);
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1, i_s1);
	return (s2);
}
