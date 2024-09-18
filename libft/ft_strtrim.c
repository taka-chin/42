/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:21:52 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/20 21:12:02 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_set_count_forward(char const *s1, char const *set)
{
	size_t		count;
	const char	*tmp;

	count = 0;
	tmp = set;
	while (*s1)
	{
		set = tmp;
		while (*set)
		{
			if (*s1 == *set)
			{
				count++;
				break ;
			}
			set++;
		}
		if (*set == 0)
			break ;
		s1++;
	}
	return (count);
}

static size_t	ft_set_count_back(char const *s1, char const *set,
		size_t s1_len)
{
	size_t		count;
	const char	*tmp;

	count = 0;
	s1 = s1 + s1_len - 1;
	tmp = set;
	while (*s1)
	{
		set = tmp;
		while (*set)
		{
			if (*s1 == *set)
			{
				count++;
				break ;
			}
			set++;
		}
		if (*set == 0)
			break ;
		s1--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	forword_s1_len;
	size_t	back_s1_len;
	size_t	trim_len;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	forword_s1_len = ft_set_count_forward(s1, set);
	back_s1_len = ft_set_count_back(s1, set, s1_len);
	trim_len = s1_len - forword_s1_len - back_s1_len;
	result = ft_substr(s1, forword_s1_len, trim_len);
	return (result);
}

/* int main(void) */
/* { */
/* 	char s1[20]= "3142Tokyo12"; */
/* 	size_t s1_len; */

/* 	s1_len = ft_strlen(s1); */
/* 	/1* printf("%d\n",ft_set_count_forward("3142Tokyo12","1234")); *1/ */
/* 	/1* printf("%d\n",ft_set_count_back("12Tokyo1234","1234",s1_len)); *1/ */
/* 	/1* printf("%d\n",ft_set_count_back("121234","1234")); *1/ */
/* 	printf("%s\n",ft_strtrim("12Tokyo1234","1234")); */
/* } */
