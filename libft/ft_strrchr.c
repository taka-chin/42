/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:51:51 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/26 14:50:40 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	if (c == '\0')
	{
		return ((char *)s + ft_strlen(s));
	}
	while (*s)
	{
		if (*s == (char)c)
		{
			result = (char *)s;
		}
		s++;
	}
	return (result);
}

/* #include <string.h> */
/* #include <stdio.h> */

/* int main(void) */
/* { */
/* 	char str[] = "abcdefghijklmnabcdefghijklmn", *p; */
/* 	int c; */

/* 	/1* printf("検索文字を入力してください。"); *1/ */
/* 	/1* c = getchar(); *1/ */

/* 	p = ft_strrchr(str, '\0'); */
/* 	p = strrchr(str, '\0'); */
/* 	/1* p = strchr(str, 'l'-256); *1/ */
/* 	if (p != NULL) { */
/* 		printf("%cは文字列の%ld番目にあります。\n", c, p-str); */
/* 		printf("以降の文字列は%sです。\n", p); */
/* 	} */
/* 	else */
/* 		printf("%cは見つかりませんでした\n", c); */

/* 	return (0); */
/* } */
