/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 08:58:39 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/22 10:34:28 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	s1_lenght;

	s1_lenght = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (NULL);
	while (*s1 && ft_strchr((const char *)set, *s1))
		s1++;
	s1_lenght = ft_strlen(s1);
	while (s1_lenght && ft_strchr((const char *)set, s1[s1_lenght]))
		s1_lenght--;
	s2 = ft_substr((const char *)s1, 0, s1_lenght + 1);
	return (s2);
}
