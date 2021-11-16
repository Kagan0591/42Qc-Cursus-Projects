/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 16:37:48 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/21 15:38:56 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordlenght(const char *s, const char delemiter, size_t i_s)
{
	size_t	count_char;

	count_char = 0;
	while (s[i_s] != '\0')
	{
		if ((char)s[i_s] == delemiter)
			return (count_char);
		while ((char)s[i_s] != delemiter && s[i_s] != '\0')
		{
			count_char++;
			i_s++;
		}
	}
	return (count_char);
}

static size_t	count_words(char *s, char delemiter, size_t i_s, size_t count)
{
	while (s[i_s] != '\0')
	{
		if (s[i_s] != delemiter)
		{
			count++;
			while (s[i_s] != delemiter && s[i_s] != '\0')
				i_s++;
			count_words(s, delemiter, i_s, count);
		}
		else
			i_s++;
	}
	return (count);
}

static void	makestr(char *string_source, char **string_master, char c)
{
	size_t	string_source_lenght;
	size_t	i_string_master;
	size_t	lenght_of_word;

	string_source_lenght = 0;
	i_string_master = 0;
	lenght_of_word = 0;
	while (string_source[string_source_lenght] != '\0')
	{
		while (string_source[string_source_lenght] == c)
			string_source_lenght++;
		lenght_of_word = wordlenght(string_source, c, string_source_lenght);
		if (lenght_of_word != 0)
		{
			string_master[i_string_master] = ft_substr(\
				string_source, (unsigned int) string_source_lenght, \
					lenght_of_word);
			string_source_lenght = string_source_lenght + lenght_of_word;
			i_string_master++;
		}
	}
	string_master[i_string_master] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	lenght_of_word;
	char	**master_str;

	lenght_of_word = 0;
	if (!s)
		return (0);
	master_str = malloc((count_words((char *)s, c, 0, 0) + 1) * sizeof(char *));
	if (!master_str)
		return (0);
	makestr((char *)s, master_str, c);
	return (master_str);
}
