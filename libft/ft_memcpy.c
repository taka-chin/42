/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:34:26 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/20 16:33:28 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (!dst && !src)
	{
		return (NULL);
	}
	while (n)
	{
		*tmp_dst++ = *tmp_src++;
		n--;
	}
	return (dst);
}

/* #include <string.h> */
/* #include <stdio.h> */
/* int main(void) */
/* { */
/* 	printf("%s\n",memcpy(NULL,NULL,1)); */
/* 	printf("%s\n",ft_memcpy(NULL,NULL,1)); */

/* } */
