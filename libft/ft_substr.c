/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:37:03 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/05 21:43:54 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/* #include "libft.h" */
/* #include <stdio.h> */

/* int main(void) */
/* { */
/* 	/1* char *s = "42Tokyo"; *1/ */
/* 	char *s = "libft-test-tokyo"; */
/* 	printf("%s\n",s); */
/* 	ft_substr(s,0,100); */
/* 	printf("%s\n",ft_substr(s,0,100)); */
/* } */
