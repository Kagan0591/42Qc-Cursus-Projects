/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:32:45 by tchalifo          #+#    #+#             */
/*   Updated: 2021/09/27 08:34:48 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_lenght;
	size_t	s2_lenght;

	if (!s1)
		return ((char *) s2);
	if (!s2)
		return ((char *) s1);
	if (s1 || s2)
	{
		s1_lenght = ft_strlen(s1);
		s2_lenght = ft_strlen(s2);
		s3 = malloc((s1_lenght + s2_lenght) + 1);
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, s1, (s1_lenght + 1));
		ft_strlcat(s3, s2, ((s1_lenght + s2_lenght) + 1));
		return (s3);
	}
	return (NULL);
}
