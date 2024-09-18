/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:52:52 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/02 13:52:58 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s1;

	tmp_s1 = (unsigned char *)s;
	while (n)
	{
		if (*tmp_s1 == (unsigned char)c)
		{
			return (tmp_s1);
		}
		tmp_s1++;
		n--;
	}
	return (NULL);
}
