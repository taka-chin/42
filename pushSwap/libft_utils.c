/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:13:34 by tyamauch          #+#    #+#             */
/*   Updated: 2023/06/14 20:13:39 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (dstsize == 0)
	{
		return (len);
	}
	while (dstsize > 1 && *src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	length;

	length = ft_strlen(s1) + 1;
	str = malloc(length);
	if (!str)
	{
		return (NULL);
	}
	ft_strlcpy(str, s1, length);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_length;

	if (!s)
		return (NULL);
	s_length = ft_strlen(s);
	if (start >= s_length || len == 0)
	{
		str = ft_strdup("");
		return (str);
	}
	else if (len > s_length - start)
		len = s_length - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
