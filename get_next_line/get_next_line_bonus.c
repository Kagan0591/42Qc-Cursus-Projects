/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:55:14 by tchalifo          #+#    #+#             */
/*   Updated: 2021/11/16 17:15:29 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remaining[OPEN_MAX];

	line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (get_line(fd, &remaining[fd]) == 0)
		return (NULL);
	line = crop_front(remaining[fd]);
	remaining[fd] = crop_end(remaining[fd]);
	return (line);
}

int	get_line(int fd, char **remaining_ptr)
{
	char		*buffer;
	int			read_output;

	read_output = 1;
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(buffer);
		return (0);
	}
	while (!ft_strchr(*remaining_ptr, '\n') && read_output != 0)
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		if (read_output == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[read_output] = '\0';
		*remaining_ptr = ft_memjoin(*remaining_ptr, buffer);
	}
	free((void *)buffer);
	return (1);
}

char	*ft_memjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_length;
	size_t	s2_length;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (!s2 && s1)
		return (ft_strdup(s1));
	else if (s1 && s2)
	{
		s3 = malloc(sizeof(char) * (s1_length + s2_length) + 1);
		if (!s3)
			return (NULL);
		ft_strlcpy(s3, s1, (s1_length + 1));
		ft_strlcat(s3, s2, ((s1_length + s2_length) + 1));
		free((void *)s1);
		return (s3);
	}
	return (NULL);
}

char	*crop_front(char *src)
{
	int		length;
	int		i;
	char	*dst;

	length = 0;
	i = 0;
	while (src[length] != '\0' && src[length] != '\n')
		length++;
	dst = malloc(sizeof(char) * (length + 2));
	if (!dst || src[0] == '\0')
	{
		free(dst);
		return (NULL);
	}
	while (i < length + 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*crop_end(char *src)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (src != NULL || src[i] != '\0')
	{
		while (src[i + 1] != '\0' && src[i] != '\n')
			i++;
		if (src[i] == '\n' && src[i + 1] != '\0')
		{
			dst = ft_strdup(&src[i + 1]);
			free((void *)src);
			return (dst);
		}
	}
	free((void *)src);
	return (NULL);
}