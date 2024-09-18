/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <tyamauch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:34:40 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/02 13:51:38 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	len_dst;

	if (dst == NULL && dstsize == 0)
	{
		return (ft_strlen(src) + dstsize);
	}
	len_dst = ft_strlen(dst);
	len = len_dst + ft_strlen(src);
	if (len_dst >= dstsize)
	{
		return (ft_strlen(src) + dstsize);
	}
	dst = dst + ft_strlen(dst);
	while (dstsize - len_dst > 1 && *src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (len);
}
