/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:55:18 by tyamauch          #+#    #+#             */
/*   Updated: 2023/07/30 20:35:49 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_free(char *str)
{
	if (str != NULL)
		free(str);
	str = NULL;
	return (NULL);
}

char	*make_buff(int fd)
{
	char	*buf;
	ssize_t	byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	byte = read(fd, buf, BUFFER_SIZE);
	if (byte <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[byte] = '\0';
	return (buf);
}

char	*make_save(char *buf, char *save, char *nflag)
{
	char	*tmp;

	if (nflag == NULL)
	{
		if (save != NULL)
		{
			tmp = ft_strdup(save);
			free(save);
			save = ft_strjoin(tmp, buf);
			free(tmp);
		}
		else
			save = ft_strdup(buf);
	}
	else
	{
		tmp = ft_strdup(ft_strchr(save, '\n'));
		free(save);
		save = ft_strdup(tmp + 1);
		free(tmp);
	}
	return (save);
}

char	*make_lines(char *save, char *nflag)
{
	char	*line;
	char	*tmp;
	size_t	len;

	len = 0;
	if (nflag != NULL)
	{
		while (save[len] != '\n' && save[len])
			len++;
		tmp = ft_substr(save, 0, len + 1);
		line = ft_strdup(tmp);
		free(tmp);
	}
	else
		line = ft_strdup(save);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	char		*line;
	char		*nflag;

	nflag = NULL;
	while (1)
	{
		if (save != NULL && ft_strchr(save, '\n'))
			break ;
		buf = make_buff(fd);
		if (buf == NULL)
			break ;
		save = make_save(buf, save, nflag);
		free(buf);
	}
	if (save == NULL || *save == '\0')
	{
		save = ft_free(save);
		return (NULL);
	}
	line = make_lines(save, ft_strchr(save, '\n'));
	save = make_save(buf, save, ft_strchr(save, '\n'));
	return (line);
}
