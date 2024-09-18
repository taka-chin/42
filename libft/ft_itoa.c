/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyamauch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:55:14 by tyamauch          #+#    #+#             */
/*   Updated: 2022/11/22 16:34:50 by tyamauch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_digits(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count += 1;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*make_numbers(char *s, size_t size, int n)
{
	long	tmp_num;
	int		flag;

	tmp_num = n;
	flag = 0;
	if (tmp_num < 0)
	{
		tmp_num = -tmp_num;
		flag += 1;
	}
	s += size;
	*s-- = '\0';
	if (tmp_num == 0)
		*s = '0';
	while (tmp_num > 0)
	{
		*s = tmp_num % 10 + '0';
		tmp_num /= 10;
		if (tmp_num > 0)
			s--;
	}
	if (flag)
		*--s = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	size;

	size = number_digits(n);
	s = malloc(size + 1);
	if (!s)
		return (NULL);
	s = make_numbers(s, size, n);
	return (s);
}
