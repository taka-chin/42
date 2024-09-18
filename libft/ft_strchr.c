/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:08:12 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/26 14:50:09 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	result = (char *)s;
	while (*result)
	{
		if (*result == (char) c)
		{
			return (result);
		}
		result++;
	}
	if (c == '\0')
	{
		return (result);
	}
	return (NULL);
}

/* #include <string.h> */
/* #include <stdio.h> */

/* int main(void) */
/* { */
/* 	char str[] = "abcdefghijklmnabcdefghijklmn", *p; */
/* 	int c; */

/* 	/1* printf("検索文字を入力してください。"); *1/ */
/* 	/1* c = getchar(); *1/ */

/* 	p = ft_strchr(str, 'l'-256); */
/* 	/1* p = strchr(str, 'l'-256); *1/ */
/* 	if (p != NULL) { */
/* 		printf("%cは文字列の%ld番目にあります。\n", c, p-str); */
/* 		printf("以降の文字列は%sです。\n", p); */
/* 	} */
/* 	else */
/* 		printf("%cは見つかりませんでした\n", c); */

/* 	return (0); */
/* } */
