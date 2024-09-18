/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:08:18 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/26 14:55:22 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	array_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (count);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static size_t	next_head(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s == c)
	{
		s++;
	}
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	**free_all(char **s)
{
	while (*s)
	{
		free(*s);
		s++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;
	size_t	len;
	size_t	i;

	count = array_count(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < count)
	{
		len = next_head(s, c);
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		result[i] = ft_substr(s, 0, len);
		if (!result[i])
			return (free_all(result));
		s += len;
		i++;
	}
	result[i] = NULL;
	return (result);
}

//
//#include <stdio.h>
//int main(void)
//{
//	char ** result;
//	/* result = ft_split(NULL, ' '); */
//	result = ft_split(" Tripouill",' ');
//printf("%s\n",result[0]);
//printf("%s\n",result[1]);
//	result = ft_split(" Tripouille",' ');
//printf("%s\n",result[0]);
//printf("%s\n",result[1]);
//
///* printf("%s\n",result[2]); */
//}
