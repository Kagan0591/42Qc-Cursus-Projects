/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:03:49 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/22 10:23:23 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	i_s;

	i_s = 0;
	if (!s)
		return (0);
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_s)
		return (0);
	while (s[i_s])
	{
		new_s[i_s] = (*f)(i_s, s[i_s]);
		i_s++;
	}
	new_s[i_s] = '\0';
	return (new_s);
}
