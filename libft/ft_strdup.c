/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:43:58 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/05 21:35:09 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
